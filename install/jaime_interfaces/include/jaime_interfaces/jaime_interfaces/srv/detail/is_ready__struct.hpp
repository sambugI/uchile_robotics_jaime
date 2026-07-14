// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from jaime_interfaces:srv/IsReady.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "jaime_interfaces/srv/is_ready.hpp"


#ifndef JAIME_INTERFACES__SRV__DETAIL__IS_READY__STRUCT_HPP_
#define JAIME_INTERFACES__SRV__DETAIL__IS_READY__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__jaime_interfaces__srv__IsReady_Request __attribute__((deprecated))
#else
# define DEPRECATED__jaime_interfaces__srv__IsReady_Request __declspec(deprecated)
#endif

namespace jaime_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct IsReady_Request_
{
  using Type = IsReady_Request_<ContainerAllocator>;

  explicit IsReady_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  explicit IsReady_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  // field types and members
  using _structure_needs_at_least_one_member_type =
    uint8_t;
  _structure_needs_at_least_one_member_type structure_needs_at_least_one_member;


  // constant declarations

  // pointer types
  using RawPtr =
    jaime_interfaces::srv::IsReady_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const jaime_interfaces::srv::IsReady_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<jaime_interfaces::srv::IsReady_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<jaime_interfaces::srv::IsReady_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      jaime_interfaces::srv::IsReady_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<jaime_interfaces::srv::IsReady_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      jaime_interfaces::srv::IsReady_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<jaime_interfaces::srv::IsReady_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<jaime_interfaces::srv::IsReady_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<jaime_interfaces::srv::IsReady_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__jaime_interfaces__srv__IsReady_Request
    std::shared_ptr<jaime_interfaces::srv::IsReady_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__jaime_interfaces__srv__IsReady_Request
    std::shared_ptr<jaime_interfaces::srv::IsReady_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const IsReady_Request_ & other) const
  {
    if (this->structure_needs_at_least_one_member != other.structure_needs_at_least_one_member) {
      return false;
    }
    return true;
  }
  bool operator!=(const IsReady_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct IsReady_Request_

// alias to use template instance with default allocator
using IsReady_Request =
  jaime_interfaces::srv::IsReady_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace jaime_interfaces


#ifndef _WIN32
# define DEPRECATED__jaime_interfaces__srv__IsReady_Response __attribute__((deprecated))
#else
# define DEPRECATED__jaime_interfaces__srv__IsReady_Response __declspec(deprecated)
#endif

namespace jaime_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct IsReady_Response_
{
  using Type = IsReady_Response_<ContainerAllocator>;

  explicit IsReady_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->ready = false;
      this->message = "";
    }
  }

  explicit IsReady_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->ready = false;
      this->message = "";
    }
  }

  // field types and members
  using _ready_type =
    bool;
  _ready_type ready;
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;

  // setters for named parameter idiom
  Type & set__ready(
    const bool & _arg)
  {
    this->ready = _arg;
    return *this;
  }
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->message = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    jaime_interfaces::srv::IsReady_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const jaime_interfaces::srv::IsReady_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<jaime_interfaces::srv::IsReady_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<jaime_interfaces::srv::IsReady_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      jaime_interfaces::srv::IsReady_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<jaime_interfaces::srv::IsReady_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      jaime_interfaces::srv::IsReady_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<jaime_interfaces::srv::IsReady_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<jaime_interfaces::srv::IsReady_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<jaime_interfaces::srv::IsReady_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__jaime_interfaces__srv__IsReady_Response
    std::shared_ptr<jaime_interfaces::srv::IsReady_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__jaime_interfaces__srv__IsReady_Response
    std::shared_ptr<jaime_interfaces::srv::IsReady_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const IsReady_Response_ & other) const
  {
    if (this->ready != other.ready) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    return true;
  }
  bool operator!=(const IsReady_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct IsReady_Response_

// alias to use template instance with default allocator
using IsReady_Response =
  jaime_interfaces::srv::IsReady_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace jaime_interfaces


// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__jaime_interfaces__srv__IsReady_Event __attribute__((deprecated))
#else
# define DEPRECATED__jaime_interfaces__srv__IsReady_Event __declspec(deprecated)
#endif

namespace jaime_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct IsReady_Event_
{
  using Type = IsReady_Event_<ContainerAllocator>;

  explicit IsReady_Event_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_init)
  {
    (void)_init;
  }

  explicit IsReady_Event_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _info_type =
    service_msgs::msg::ServiceEventInfo_<ContainerAllocator>;
  _info_type info;
  using _request_type =
    rosidl_runtime_cpp::BoundedVector<jaime_interfaces::srv::IsReady_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<jaime_interfaces::srv::IsReady_Request_<ContainerAllocator>>>;
  _request_type request;
  using _response_type =
    rosidl_runtime_cpp::BoundedVector<jaime_interfaces::srv::IsReady_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<jaime_interfaces::srv::IsReady_Response_<ContainerAllocator>>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__info(
    const service_msgs::msg::ServiceEventInfo_<ContainerAllocator> & _arg)
  {
    this->info = _arg;
    return *this;
  }
  Type & set__request(
    const rosidl_runtime_cpp::BoundedVector<jaime_interfaces::srv::IsReady_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<jaime_interfaces::srv::IsReady_Request_<ContainerAllocator>>> & _arg)
  {
    this->request = _arg;
    return *this;
  }
  Type & set__response(
    const rosidl_runtime_cpp::BoundedVector<jaime_interfaces::srv::IsReady_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<jaime_interfaces::srv::IsReady_Response_<ContainerAllocator>>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    jaime_interfaces::srv::IsReady_Event_<ContainerAllocator> *;
  using ConstRawPtr =
    const jaime_interfaces::srv::IsReady_Event_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<jaime_interfaces::srv::IsReady_Event_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<jaime_interfaces::srv::IsReady_Event_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      jaime_interfaces::srv::IsReady_Event_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<jaime_interfaces::srv::IsReady_Event_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      jaime_interfaces::srv::IsReady_Event_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<jaime_interfaces::srv::IsReady_Event_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<jaime_interfaces::srv::IsReady_Event_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<jaime_interfaces::srv::IsReady_Event_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__jaime_interfaces__srv__IsReady_Event
    std::shared_ptr<jaime_interfaces::srv::IsReady_Event_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__jaime_interfaces__srv__IsReady_Event
    std::shared_ptr<jaime_interfaces::srv::IsReady_Event_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const IsReady_Event_ & other) const
  {
    if (this->info != other.info) {
      return false;
    }
    if (this->request != other.request) {
      return false;
    }
    if (this->response != other.response) {
      return false;
    }
    return true;
  }
  bool operator!=(const IsReady_Event_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct IsReady_Event_

// alias to use template instance with default allocator
using IsReady_Event =
  jaime_interfaces::srv::IsReady_Event_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace jaime_interfaces

namespace jaime_interfaces
{

namespace srv
{

struct IsReady
{
  using Request = jaime_interfaces::srv::IsReady_Request;
  using Response = jaime_interfaces::srv::IsReady_Response;
  using Event = jaime_interfaces::srv::IsReady_Event;
};

}  // namespace srv

}  // namespace jaime_interfaces

#endif  // JAIME_INTERFACES__SRV__DETAIL__IS_READY__STRUCT_HPP_
