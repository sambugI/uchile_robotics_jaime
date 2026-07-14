// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from jaime_interfaces:action/MoveToPose.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "jaime_interfaces/action/move_to_pose.hpp"


#ifndef JAIME_INTERFACES__ACTION__DETAIL__MOVE_TO_POSE__BUILDER_HPP_
#define JAIME_INTERFACES__ACTION__DETAIL__MOVE_TO_POSE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "jaime_interfaces/action/detail/move_to_pose__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace jaime_interfaces
{

namespace action
{

namespace builder
{

class Init_MoveToPose_Goal_target_position
{
public:
  Init_MoveToPose_Goal_target_position()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::jaime_interfaces::action::MoveToPose_Goal target_position(::jaime_interfaces::action::MoveToPose_Goal::_target_position_type arg)
  {
    msg_.target_position = std::move(arg);
    return std::move(msg_);
  }

private:
  ::jaime_interfaces::action::MoveToPose_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::jaime_interfaces::action::MoveToPose_Goal>()
{
  return jaime_interfaces::action::builder::Init_MoveToPose_Goal_target_position();
}

}  // namespace jaime_interfaces


namespace jaime_interfaces
{

namespace action
{

namespace builder
{

class Init_MoveToPose_Result_message
{
public:
  explicit Init_MoveToPose_Result_message(::jaime_interfaces::action::MoveToPose_Result & msg)
  : msg_(msg)
  {}
  ::jaime_interfaces::action::MoveToPose_Result message(::jaime_interfaces::action::MoveToPose_Result::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::jaime_interfaces::action::MoveToPose_Result msg_;
};

class Init_MoveToPose_Result_success
{
public:
  Init_MoveToPose_Result_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveToPose_Result_message success(::jaime_interfaces::action::MoveToPose_Result::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_MoveToPose_Result_message(msg_);
  }

private:
  ::jaime_interfaces::action::MoveToPose_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::jaime_interfaces::action::MoveToPose_Result>()
{
  return jaime_interfaces::action::builder::Init_MoveToPose_Result_success();
}

}  // namespace jaime_interfaces


namespace jaime_interfaces
{

namespace action
{

namespace builder
{

class Init_MoveToPose_Feedback_error
{
public:
  Init_MoveToPose_Feedback_error()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::jaime_interfaces::action::MoveToPose_Feedback error(::jaime_interfaces::action::MoveToPose_Feedback::_error_type arg)
  {
    msg_.error = std::move(arg);
    return std::move(msg_);
  }

private:
  ::jaime_interfaces::action::MoveToPose_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::jaime_interfaces::action::MoveToPose_Feedback>()
{
  return jaime_interfaces::action::builder::Init_MoveToPose_Feedback_error();
}

}  // namespace jaime_interfaces


namespace jaime_interfaces
{

namespace action
{

namespace builder
{

class Init_MoveToPose_SendGoal_Request_goal
{
public:
  explicit Init_MoveToPose_SendGoal_Request_goal(::jaime_interfaces::action::MoveToPose_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::jaime_interfaces::action::MoveToPose_SendGoal_Request goal(::jaime_interfaces::action::MoveToPose_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::jaime_interfaces::action::MoveToPose_SendGoal_Request msg_;
};

class Init_MoveToPose_SendGoal_Request_goal_id
{
public:
  Init_MoveToPose_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveToPose_SendGoal_Request_goal goal_id(::jaime_interfaces::action::MoveToPose_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_MoveToPose_SendGoal_Request_goal(msg_);
  }

private:
  ::jaime_interfaces::action::MoveToPose_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::jaime_interfaces::action::MoveToPose_SendGoal_Request>()
{
  return jaime_interfaces::action::builder::Init_MoveToPose_SendGoal_Request_goal_id();
}

}  // namespace jaime_interfaces


namespace jaime_interfaces
{

namespace action
{

namespace builder
{

class Init_MoveToPose_SendGoal_Response_stamp
{
public:
  explicit Init_MoveToPose_SendGoal_Response_stamp(::jaime_interfaces::action::MoveToPose_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::jaime_interfaces::action::MoveToPose_SendGoal_Response stamp(::jaime_interfaces::action::MoveToPose_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::jaime_interfaces::action::MoveToPose_SendGoal_Response msg_;
};

class Init_MoveToPose_SendGoal_Response_accepted
{
public:
  Init_MoveToPose_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveToPose_SendGoal_Response_stamp accepted(::jaime_interfaces::action::MoveToPose_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_MoveToPose_SendGoal_Response_stamp(msg_);
  }

private:
  ::jaime_interfaces::action::MoveToPose_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::jaime_interfaces::action::MoveToPose_SendGoal_Response>()
{
  return jaime_interfaces::action::builder::Init_MoveToPose_SendGoal_Response_accepted();
}

}  // namespace jaime_interfaces


namespace jaime_interfaces
{

namespace action
{

namespace builder
{

class Init_MoveToPose_SendGoal_Event_response
{
public:
  explicit Init_MoveToPose_SendGoal_Event_response(::jaime_interfaces::action::MoveToPose_SendGoal_Event & msg)
  : msg_(msg)
  {}
  ::jaime_interfaces::action::MoveToPose_SendGoal_Event response(::jaime_interfaces::action::MoveToPose_SendGoal_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::jaime_interfaces::action::MoveToPose_SendGoal_Event msg_;
};

class Init_MoveToPose_SendGoal_Event_request
{
public:
  explicit Init_MoveToPose_SendGoal_Event_request(::jaime_interfaces::action::MoveToPose_SendGoal_Event & msg)
  : msg_(msg)
  {}
  Init_MoveToPose_SendGoal_Event_response request(::jaime_interfaces::action::MoveToPose_SendGoal_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_MoveToPose_SendGoal_Event_response(msg_);
  }

private:
  ::jaime_interfaces::action::MoveToPose_SendGoal_Event msg_;
};

class Init_MoveToPose_SendGoal_Event_info
{
public:
  Init_MoveToPose_SendGoal_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveToPose_SendGoal_Event_request info(::jaime_interfaces::action::MoveToPose_SendGoal_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_MoveToPose_SendGoal_Event_request(msg_);
  }

private:
  ::jaime_interfaces::action::MoveToPose_SendGoal_Event msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::jaime_interfaces::action::MoveToPose_SendGoal_Event>()
{
  return jaime_interfaces::action::builder::Init_MoveToPose_SendGoal_Event_info();
}

}  // namespace jaime_interfaces


namespace jaime_interfaces
{

namespace action
{

namespace builder
{

class Init_MoveToPose_GetResult_Request_goal_id
{
public:
  Init_MoveToPose_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::jaime_interfaces::action::MoveToPose_GetResult_Request goal_id(::jaime_interfaces::action::MoveToPose_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::jaime_interfaces::action::MoveToPose_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::jaime_interfaces::action::MoveToPose_GetResult_Request>()
{
  return jaime_interfaces::action::builder::Init_MoveToPose_GetResult_Request_goal_id();
}

}  // namespace jaime_interfaces


namespace jaime_interfaces
{

namespace action
{

namespace builder
{

class Init_MoveToPose_GetResult_Response_result
{
public:
  explicit Init_MoveToPose_GetResult_Response_result(::jaime_interfaces::action::MoveToPose_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::jaime_interfaces::action::MoveToPose_GetResult_Response result(::jaime_interfaces::action::MoveToPose_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::jaime_interfaces::action::MoveToPose_GetResult_Response msg_;
};

class Init_MoveToPose_GetResult_Response_status
{
public:
  Init_MoveToPose_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveToPose_GetResult_Response_result status(::jaime_interfaces::action::MoveToPose_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_MoveToPose_GetResult_Response_result(msg_);
  }

private:
  ::jaime_interfaces::action::MoveToPose_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::jaime_interfaces::action::MoveToPose_GetResult_Response>()
{
  return jaime_interfaces::action::builder::Init_MoveToPose_GetResult_Response_status();
}

}  // namespace jaime_interfaces


namespace jaime_interfaces
{

namespace action
{

namespace builder
{

class Init_MoveToPose_GetResult_Event_response
{
public:
  explicit Init_MoveToPose_GetResult_Event_response(::jaime_interfaces::action::MoveToPose_GetResult_Event & msg)
  : msg_(msg)
  {}
  ::jaime_interfaces::action::MoveToPose_GetResult_Event response(::jaime_interfaces::action::MoveToPose_GetResult_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::jaime_interfaces::action::MoveToPose_GetResult_Event msg_;
};

class Init_MoveToPose_GetResult_Event_request
{
public:
  explicit Init_MoveToPose_GetResult_Event_request(::jaime_interfaces::action::MoveToPose_GetResult_Event & msg)
  : msg_(msg)
  {}
  Init_MoveToPose_GetResult_Event_response request(::jaime_interfaces::action::MoveToPose_GetResult_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_MoveToPose_GetResult_Event_response(msg_);
  }

private:
  ::jaime_interfaces::action::MoveToPose_GetResult_Event msg_;
};

class Init_MoveToPose_GetResult_Event_info
{
public:
  Init_MoveToPose_GetResult_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveToPose_GetResult_Event_request info(::jaime_interfaces::action::MoveToPose_GetResult_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_MoveToPose_GetResult_Event_request(msg_);
  }

private:
  ::jaime_interfaces::action::MoveToPose_GetResult_Event msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::jaime_interfaces::action::MoveToPose_GetResult_Event>()
{
  return jaime_interfaces::action::builder::Init_MoveToPose_GetResult_Event_info();
}

}  // namespace jaime_interfaces


namespace jaime_interfaces
{

namespace action
{

namespace builder
{

class Init_MoveToPose_FeedbackMessage_feedback
{
public:
  explicit Init_MoveToPose_FeedbackMessage_feedback(::jaime_interfaces::action::MoveToPose_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::jaime_interfaces::action::MoveToPose_FeedbackMessage feedback(::jaime_interfaces::action::MoveToPose_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::jaime_interfaces::action::MoveToPose_FeedbackMessage msg_;
};

class Init_MoveToPose_FeedbackMessage_goal_id
{
public:
  Init_MoveToPose_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveToPose_FeedbackMessage_feedback goal_id(::jaime_interfaces::action::MoveToPose_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_MoveToPose_FeedbackMessage_feedback(msg_);
  }

private:
  ::jaime_interfaces::action::MoveToPose_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::jaime_interfaces::action::MoveToPose_FeedbackMessage>()
{
  return jaime_interfaces::action::builder::Init_MoveToPose_FeedbackMessage_goal_id();
}

}  // namespace jaime_interfaces

#endif  // JAIME_INTERFACES__ACTION__DETAIL__MOVE_TO_POSE__BUILDER_HPP_
