// generated from rosidl_typesupport_c/resource/idl__type_support.cpp.em
// with input from jaime_interfaces:srv/IsReady.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "jaime_interfaces/srv/detail/is_ready__struct.h"
#include "jaime_interfaces/srv/detail/is_ready__type_support.h"
#include "jaime_interfaces/srv/detail/is_ready__functions.h"
#include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/message_type_support_dispatch.h"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_c/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace jaime_interfaces
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _IsReady_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _IsReady_Request_type_support_ids_t;

static const _IsReady_Request_type_support_ids_t _IsReady_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _IsReady_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _IsReady_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _IsReady_Request_type_support_symbol_names_t _IsReady_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, jaime_interfaces, srv, IsReady_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, jaime_interfaces, srv, IsReady_Request)),
  }
};

typedef struct _IsReady_Request_type_support_data_t
{
  void * data[2];
} _IsReady_Request_type_support_data_t;

static _IsReady_Request_type_support_data_t _IsReady_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _IsReady_Request_message_typesupport_map = {
  2,
  "jaime_interfaces",
  &_IsReady_Request_message_typesupport_ids.typesupport_identifier[0],
  &_IsReady_Request_message_typesupport_symbol_names.symbol_name[0],
  &_IsReady_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t IsReady_Request_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_IsReady_Request_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &jaime_interfaces__srv__IsReady_Request__get_type_hash,
  &jaime_interfaces__srv__IsReady_Request__get_type_description,
  &jaime_interfaces__srv__IsReady_Request__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace jaime_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, jaime_interfaces, srv, IsReady_Request)() {
  return &::jaime_interfaces::srv::rosidl_typesupport_c::IsReady_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "jaime_interfaces/srv/detail/is_ready__struct.h"
// already included above
// #include "jaime_interfaces/srv/detail/is_ready__type_support.h"
// already included above
// #include "jaime_interfaces/srv/detail/is_ready__functions.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace jaime_interfaces
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _IsReady_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _IsReady_Response_type_support_ids_t;

static const _IsReady_Response_type_support_ids_t _IsReady_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _IsReady_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _IsReady_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _IsReady_Response_type_support_symbol_names_t _IsReady_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, jaime_interfaces, srv, IsReady_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, jaime_interfaces, srv, IsReady_Response)),
  }
};

typedef struct _IsReady_Response_type_support_data_t
{
  void * data[2];
} _IsReady_Response_type_support_data_t;

static _IsReady_Response_type_support_data_t _IsReady_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _IsReady_Response_message_typesupport_map = {
  2,
  "jaime_interfaces",
  &_IsReady_Response_message_typesupport_ids.typesupport_identifier[0],
  &_IsReady_Response_message_typesupport_symbol_names.symbol_name[0],
  &_IsReady_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t IsReady_Response_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_IsReady_Response_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &jaime_interfaces__srv__IsReady_Response__get_type_hash,
  &jaime_interfaces__srv__IsReady_Response__get_type_description,
  &jaime_interfaces__srv__IsReady_Response__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace jaime_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, jaime_interfaces, srv, IsReady_Response)() {
  return &::jaime_interfaces::srv::rosidl_typesupport_c::IsReady_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "jaime_interfaces/srv/detail/is_ready__struct.h"
// already included above
// #include "jaime_interfaces/srv/detail/is_ready__type_support.h"
// already included above
// #include "jaime_interfaces/srv/detail/is_ready__functions.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace jaime_interfaces
{

namespace srv
{

namespace rosidl_typesupport_c
{

typedef struct _IsReady_Event_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _IsReady_Event_type_support_ids_t;

static const _IsReady_Event_type_support_ids_t _IsReady_Event_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _IsReady_Event_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _IsReady_Event_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _IsReady_Event_type_support_symbol_names_t _IsReady_Event_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, jaime_interfaces, srv, IsReady_Event)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, jaime_interfaces, srv, IsReady_Event)),
  }
};

typedef struct _IsReady_Event_type_support_data_t
{
  void * data[2];
} _IsReady_Event_type_support_data_t;

static _IsReady_Event_type_support_data_t _IsReady_Event_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _IsReady_Event_message_typesupport_map = {
  2,
  "jaime_interfaces",
  &_IsReady_Event_message_typesupport_ids.typesupport_identifier[0],
  &_IsReady_Event_message_typesupport_symbol_names.symbol_name[0],
  &_IsReady_Event_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t IsReady_Event_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_IsReady_Event_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
  &jaime_interfaces__srv__IsReady_Event__get_type_hash,
  &jaime_interfaces__srv__IsReady_Event__get_type_description,
  &jaime_interfaces__srv__IsReady_Event__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace jaime_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, jaime_interfaces, srv, IsReady_Event)() {
  return &::jaime_interfaces::srv::rosidl_typesupport_c::IsReady_Event_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "jaime_interfaces/srv/detail/is_ready__type_support.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/service_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
#include "service_msgs/msg/service_event_info.h"
#include "builtin_interfaces/msg/time.h"

namespace jaime_interfaces
{

namespace srv
{

namespace rosidl_typesupport_c
{
typedef struct _IsReady_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _IsReady_type_support_ids_t;

static const _IsReady_type_support_ids_t _IsReady_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _IsReady_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _IsReady_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _IsReady_type_support_symbol_names_t _IsReady_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, jaime_interfaces, srv, IsReady)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, jaime_interfaces, srv, IsReady)),
  }
};

typedef struct _IsReady_type_support_data_t
{
  void * data[2];
} _IsReady_type_support_data_t;

static _IsReady_type_support_data_t _IsReady_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _IsReady_service_typesupport_map = {
  2,
  "jaime_interfaces",
  &_IsReady_service_typesupport_ids.typesupport_identifier[0],
  &_IsReady_service_typesupport_symbol_names.symbol_name[0],
  &_IsReady_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t IsReady_service_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_IsReady_service_typesupport_map),
  rosidl_typesupport_c__get_service_typesupport_handle_function,
  &IsReady_Request_message_type_support_handle,
  &IsReady_Response_message_type_support_handle,
  &IsReady_Event_message_type_support_handle,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    jaime_interfaces,
    srv,
    IsReady
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    jaime_interfaces,
    srv,
    IsReady
  ),
  &jaime_interfaces__srv__IsReady__get_type_hash,
  &jaime_interfaces__srv__IsReady__get_type_description,
  &jaime_interfaces__srv__IsReady__get_type_description_sources,
};

}  // namespace rosidl_typesupport_c

}  // namespace srv

}  // namespace jaime_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_c, jaime_interfaces, srv, IsReady)() {
  return &::jaime_interfaces::srv::rosidl_typesupport_c::IsReady_service_type_support_handle;
}

#ifdef __cplusplus
}
#endif
