#include <memory>
#include <vector>
#include <cstdint>
#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/joy.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "std_msgs/msg/float64_multi_array.hpp"

class TeleopJoy : public rclcpp::Node
{
public:
  TeleopJoy()
  : Node("teleop_node"),
    latched_(false)
  {
    // Declaración de parámetros
    this->declare_parameter<bool>("require_enable_button", true);
    this->declare_parameter<int64_t>("enable_button", 0);
    this->declare_parameter<double>("scale_linear", 1.0);
    this->declare_parameter<double>("scale_angular", 1.0);
    this->declare_parameter<double>("scale_arm", 1.0);

    // Obtención de parámetros
    require_enable_button_ = this->get_parameter("require_enable_button").as_bool();
    enable_button_ = this->get_parameter("enable_button").as_int();
    scale_linear_ = this->get_parameter("scale_linear").as_double();
    scale_angular_ = this->get_parameter("scale_angular").as_double();
    scale_arm_ = this->get_parameter("scale_arm").as_double();

    // Publicadores
    cmd_vel_pub_ = this->create_publisher<geometry_msgs::msg::Twist>(
      "/cmd_vel_joy", rclcpp::QoS(10));
    arm_cmd_pub_ = this->create_publisher<std_msgs::msg::Float64MultiArray>(
      "/cmd", rclcpp::QoS(10));

    // Suscriptor
    joy_sub_ = this->create_subscription<sensor_msgs::msg::Joy>(
      "/joy",
      rclcpp::QoS(10),
      std::bind(&TeleopJoy::joyCallback, this, std::placeholders::_1)
    );
  }

private:
  void joyCallback(const sensor_msgs::msg::Joy::SharedPtr msg)
  {
    geometry_msgs::msg::Twist v;

    if (latched_) {
      cmd_vel_pub_->publish(v);
      if (msg->buttons.size() > 0 && msg->axes.size() > 2) {
        if (msg->buttons[0] == 1 && msg->axes[2] < -0.9) {
          latched_ = false;
          RCLCPP_INFO(this->get_logger(), "latching_se detuvo");
        }
      }
    }
    else if (msg->buttons.size() > 1 && msg->buttons[1] == 1) {
      latched_ = true;
      cmd_vel_pub_->publish(v);
      RCLCPP_INFO(this->get_logger(), "avanzar");
    }
    else {
      // Verificación del botón de seguridad (Deadman switch)
      bool button_pressed = false;
      if (enable_button_ >= 0 && static_cast<size_t>(enable_button_) < msg->buttons.size()) {
        button_pressed = (msg->buttons[enable_button_] == 1);
      }

      if (require_enable_button_ && !button_pressed) {
        // Velocidad 0 si no se presiona el botón de seguridad
        v.linear.x = 0.0;
        v.angular.z = 0.0;
      } else {
        if (msg->axes.size() > 1) {
          v.linear.x  = msg->axes[1] * scale_linear_;
          v.angular.z = msg->axes[0] * scale_angular_;
        }
      }
      cmd_vel_pub_->publish(v);
    }

    // Control del cuello / brazo
    std_msgs::msg::Float64MultiArray arm_msg;
    double vz = 0.0;
    
    if (msg->axes.size() > 4) {
      vz = msg->axes[4] * scale_arm_;
    }

    //if (msg->buttons.size() >= 13) {
    //  if (msg->buttons[11] == 1) {
    //    vz = scale_arm_;
    //  }
    //  else if (msg->buttons[12] == 1) {
    //    vz = -scale_arm_;
    //  }
    //}

    arm_msg.data = {0.0, 0.0, vz};
    arm_cmd_pub_->publish(arm_msg);
  }

  bool latched_;
  bool require_enable_button_;
  int64_t enable_button_;
  double scale_linear_;
  double scale_angular_;
  double scale_arm_;

  rclcpp::Subscription<sensor_msgs::msg::Joy>::SharedPtr joy_sub_;
  rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_pub_;
  rclcpp::Publisher<std_msgs::msg::Float64MultiArray>::SharedPtr arm_cmd_pub_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<TeleopJoy>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}