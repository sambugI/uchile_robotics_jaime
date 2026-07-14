// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from jaime_interfaces:srv/IsReady.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "jaime_interfaces/srv/is_ready.hpp"


#ifndef JAIME_INTERFACES__SRV__DETAIL__IS_READY__BUILDER_HPP_
#define JAIME_INTERFACES__SRV__DETAIL__IS_READY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "jaime_interfaces/srv/detail/is_ready__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace jaime_interfaces
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::jaime_interfaces::srv::IsReady_Request>()
{
  return ::jaime_interfaces::srv::IsReady_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace jaime_interfaces


namespace jaime_interfaces
{

namespace srv
{

namespace builder
{

class Init_IsReady_Response_message
{
public:
  explicit Init_IsReady_Response_message(::jaime_interfaces::srv::IsReady_Response & msg)
  : msg_(msg)
  {}
  ::jaime_interfaces::srv::IsReady_Response message(::jaime_interfaces::srv::IsReady_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::jaime_interfaces::srv::IsReady_Response msg_;
};

class Init_IsReady_Response_ready
{
public:
  Init_IsReady_Response_ready()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_IsReady_Response_message ready(::jaime_interfaces::srv::IsReady_Response::_ready_type arg)
  {
    msg_.ready = std::move(arg);
    return Init_IsReady_Response_message(msg_);
  }

private:
  ::jaime_interfaces::srv::IsReady_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::jaime_interfaces::srv::IsReady_Response>()
{
  return jaime_interfaces::srv::builder::Init_IsReady_Response_ready();
}

}  // namespace jaime_interfaces


namespace jaime_interfaces
{

namespace srv
{

namespace builder
{

class Init_IsReady_Event_response
{
public:
  explicit Init_IsReady_Event_response(::jaime_interfaces::srv::IsReady_Event & msg)
  : msg_(msg)
  {}
  ::jaime_interfaces::srv::IsReady_Event response(::jaime_interfaces::srv::IsReady_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::jaime_interfaces::srv::IsReady_Event msg_;
};

class Init_IsReady_Event_request
{
public:
  explicit Init_IsReady_Event_request(::jaime_interfaces::srv::IsReady_Event & msg)
  : msg_(msg)
  {}
  Init_IsReady_Event_response request(::jaime_interfaces::srv::IsReady_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_IsReady_Event_response(msg_);
  }

private:
  ::jaime_interfaces::srv::IsReady_Event msg_;
};

class Init_IsReady_Event_info
{
public:
  Init_IsReady_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_IsReady_Event_request info(::jaime_interfaces::srv::IsReady_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_IsReady_Event_request(msg_);
  }

private:
  ::jaime_interfaces::srv::IsReady_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::jaime_interfaces::srv::IsReady_Event>()
{
  return jaime_interfaces::srv::builder::Init_IsReady_Event_info();
}

}  // namespace jaime_interfaces

#endif  // JAIME_INTERFACES__SRV__DETAIL__IS_READY__BUILDER_HPP_
