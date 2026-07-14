// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from jaime_interfaces:srv/IsReady.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "jaime_interfaces/srv/is_ready.h"


#ifndef JAIME_INTERFACES__SRV__DETAIL__IS_READY__STRUCT_H_
#define JAIME_INTERFACES__SRV__DETAIL__IS_READY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/IsReady in the package jaime_interfaces.
typedef struct jaime_interfaces__srv__IsReady_Request
{
  uint8_t structure_needs_at_least_one_member;
} jaime_interfaces__srv__IsReady_Request;

// Struct for a sequence of jaime_interfaces__srv__IsReady_Request.
typedef struct jaime_interfaces__srv__IsReady_Request__Sequence
{
  jaime_interfaces__srv__IsReady_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} jaime_interfaces__srv__IsReady_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/IsReady in the package jaime_interfaces.
typedef struct jaime_interfaces__srv__IsReady_Response
{
  bool ready;
  rosidl_runtime_c__String message;
} jaime_interfaces__srv__IsReady_Response;

// Struct for a sequence of jaime_interfaces__srv__IsReady_Response.
typedef struct jaime_interfaces__srv__IsReady_Response__Sequence
{
  jaime_interfaces__srv__IsReady_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} jaime_interfaces__srv__IsReady_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  jaime_interfaces__srv__IsReady_Event__request__MAX_SIZE = 1
};
// response
enum
{
  jaime_interfaces__srv__IsReady_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/IsReady in the package jaime_interfaces.
typedef struct jaime_interfaces__srv__IsReady_Event
{
  service_msgs__msg__ServiceEventInfo info;
  jaime_interfaces__srv__IsReady_Request__Sequence request;
  jaime_interfaces__srv__IsReady_Response__Sequence response;
} jaime_interfaces__srv__IsReady_Event;

// Struct for a sequence of jaime_interfaces__srv__IsReady_Event.
typedef struct jaime_interfaces__srv__IsReady_Event__Sequence
{
  jaime_interfaces__srv__IsReady_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} jaime_interfaces__srv__IsReady_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // JAIME_INTERFACES__SRV__DETAIL__IS_READY__STRUCT_H_
