// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from jaime_interfaces:srv/IsReady.idl
// generated code does not contain a copyright notice

#include "jaime_interfaces/srv/detail/is_ready__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_jaime_interfaces
const rosidl_type_hash_t *
jaime_interfaces__srv__IsReady__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x97, 0x8a, 0xda, 0x24, 0x71, 0x0c, 0xdb, 0xed,
      0x4d, 0x7b, 0x0f, 0xea, 0x47, 0x61, 0x21, 0xf4,
      0xb6, 0xfd, 0x17, 0x5b, 0xa3, 0x4d, 0x3a, 0xda,
      0x6d, 0x46, 0xa2, 0xc9, 0xff, 0x3e, 0xcd, 0x06,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_jaime_interfaces
const rosidl_type_hash_t *
jaime_interfaces__srv__IsReady_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xec, 0x93, 0x0a, 0x13, 0x72, 0xb2, 0xa1, 0xf0,
      0x97, 0xb1, 0x6e, 0xa4, 0x63, 0xfa, 0xbb, 0x4b,
      0x1c, 0x83, 0xe9, 0x28, 0x91, 0xac, 0xca, 0x26,
      0xbd, 0x71, 0xe3, 0x19, 0xd1, 0x05, 0x06, 0xb2,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_jaime_interfaces
const rosidl_type_hash_t *
jaime_interfaces__srv__IsReady_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x1f, 0x7c, 0x25, 0x7c, 0xce, 0x34, 0x46, 0x9b,
      0x4c, 0x6a, 0xdd, 0x37, 0x90, 0x1c, 0x99, 0x87,
      0xbc, 0x35, 0xb3, 0x56, 0x54, 0x84, 0xf1, 0xc3,
      0xa3, 0x1e, 0x52, 0x1a, 0x53, 0xe5, 0x66, 0x0e,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_jaime_interfaces
const rosidl_type_hash_t *
jaime_interfaces__srv__IsReady_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xc7, 0x9b, 0x3b, 0x1d, 0xca, 0xdf, 0x1e, 0x0b,
      0x9a, 0x10, 0x8d, 0xbe, 0x16, 0x6b, 0x38, 0xf5,
      0x86, 0x29, 0xe3, 0x7e, 0x86, 0xb7, 0xb2, 0xf3,
      0xe8, 0x77, 0x2f, 0x7a, 0x1f, 0xb7, 0x7f, 0x41,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "service_msgs/msg/detail/service_event_info__functions.h"
#include "builtin_interfaces/msg/detail/time__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t service_msgs__msg__ServiceEventInfo__EXPECTED_HASH = {1, {
    0x41, 0xbc, 0xbb, 0xe0, 0x7a, 0x75, 0xc9, 0xb5,
    0x2b, 0xc9, 0x6b, 0xfd, 0x5c, 0x24, 0xd7, 0xf0,
    0xfc, 0x0a, 0x08, 0xc0, 0xcb, 0x79, 0x21, 0xb3,
    0x37, 0x3c, 0x57, 0x32, 0x34, 0x5a, 0x6f, 0x45,
  }};
#endif

static char jaime_interfaces__srv__IsReady__TYPE_NAME[] = "jaime_interfaces/srv/IsReady";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char jaime_interfaces__srv__IsReady_Event__TYPE_NAME[] = "jaime_interfaces/srv/IsReady_Event";
static char jaime_interfaces__srv__IsReady_Request__TYPE_NAME[] = "jaime_interfaces/srv/IsReady_Request";
static char jaime_interfaces__srv__IsReady_Response__TYPE_NAME[] = "jaime_interfaces/srv/IsReady_Response";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";

// Define type names, field names, and default values
static char jaime_interfaces__srv__IsReady__FIELD_NAME__request_message[] = "request_message";
static char jaime_interfaces__srv__IsReady__FIELD_NAME__response_message[] = "response_message";
static char jaime_interfaces__srv__IsReady__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field jaime_interfaces__srv__IsReady__FIELDS[] = {
  {
    {jaime_interfaces__srv__IsReady__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {jaime_interfaces__srv__IsReady_Request__TYPE_NAME, 36, 36},
    },
    {NULL, 0, 0},
  },
  {
    {jaime_interfaces__srv__IsReady__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {jaime_interfaces__srv__IsReady_Response__TYPE_NAME, 37, 37},
    },
    {NULL, 0, 0},
  },
  {
    {jaime_interfaces__srv__IsReady__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {jaime_interfaces__srv__IsReady_Event__TYPE_NAME, 34, 34},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription jaime_interfaces__srv__IsReady__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {jaime_interfaces__srv__IsReady_Event__TYPE_NAME, 34, 34},
    {NULL, 0, 0},
  },
  {
    {jaime_interfaces__srv__IsReady_Request__TYPE_NAME, 36, 36},
    {NULL, 0, 0},
  },
  {
    {jaime_interfaces__srv__IsReady_Response__TYPE_NAME, 37, 37},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
jaime_interfaces__srv__IsReady__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {jaime_interfaces__srv__IsReady__TYPE_NAME, 28, 28},
      {jaime_interfaces__srv__IsReady__FIELDS, 3, 3},
    },
    {jaime_interfaces__srv__IsReady__REFERENCED_TYPE_DESCRIPTIONS, 5, 5},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = jaime_interfaces__srv__IsReady_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = jaime_interfaces__srv__IsReady_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = jaime_interfaces__srv__IsReady_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char jaime_interfaces__srv__IsReady_Request__FIELD_NAME__structure_needs_at_least_one_member[] = "structure_needs_at_least_one_member";

static rosidl_runtime_c__type_description__Field jaime_interfaces__srv__IsReady_Request__FIELDS[] = {
  {
    {jaime_interfaces__srv__IsReady_Request__FIELD_NAME__structure_needs_at_least_one_member, 35, 35},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
jaime_interfaces__srv__IsReady_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {jaime_interfaces__srv__IsReady_Request__TYPE_NAME, 36, 36},
      {jaime_interfaces__srv__IsReady_Request__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char jaime_interfaces__srv__IsReady_Response__FIELD_NAME__ready[] = "ready";
static char jaime_interfaces__srv__IsReady_Response__FIELD_NAME__message[] = "message";

static rosidl_runtime_c__type_description__Field jaime_interfaces__srv__IsReady_Response__FIELDS[] = {
  {
    {jaime_interfaces__srv__IsReady_Response__FIELD_NAME__ready, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {jaime_interfaces__srv__IsReady_Response__FIELD_NAME__message, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
jaime_interfaces__srv__IsReady_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {jaime_interfaces__srv__IsReady_Response__TYPE_NAME, 37, 37},
      {jaime_interfaces__srv__IsReady_Response__FIELDS, 2, 2},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char jaime_interfaces__srv__IsReady_Event__FIELD_NAME__info[] = "info";
static char jaime_interfaces__srv__IsReady_Event__FIELD_NAME__request[] = "request";
static char jaime_interfaces__srv__IsReady_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field jaime_interfaces__srv__IsReady_Event__FIELDS[] = {
  {
    {jaime_interfaces__srv__IsReady_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {jaime_interfaces__srv__IsReady_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {jaime_interfaces__srv__IsReady_Request__TYPE_NAME, 36, 36},
    },
    {NULL, 0, 0},
  },
  {
    {jaime_interfaces__srv__IsReady_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {jaime_interfaces__srv__IsReady_Response__TYPE_NAME, 37, 37},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription jaime_interfaces__srv__IsReady_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {jaime_interfaces__srv__IsReady_Request__TYPE_NAME, 36, 36},
    {NULL, 0, 0},
  },
  {
    {jaime_interfaces__srv__IsReady_Response__TYPE_NAME, 37, 37},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
jaime_interfaces__srv__IsReady_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {jaime_interfaces__srv__IsReady_Event__TYPE_NAME, 34, 34},
      {jaime_interfaces__srv__IsReady_Event__FIELDS, 3, 3},
    },
    {jaime_interfaces__srv__IsReady_Event__REFERENCED_TYPE_DESCRIPTIONS, 4, 4},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[1].fields = jaime_interfaces__srv__IsReady_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = jaime_interfaces__srv__IsReady_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[3].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "---\n"
  "bool ready\n"
  "string message";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
jaime_interfaces__srv__IsReady__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {jaime_interfaces__srv__IsReady__TYPE_NAME, 28, 28},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 29, 29},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
jaime_interfaces__srv__IsReady_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {jaime_interfaces__srv__IsReady_Request__TYPE_NAME, 36, 36},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
jaime_interfaces__srv__IsReady_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {jaime_interfaces__srv__IsReady_Response__TYPE_NAME, 37, 37},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
jaime_interfaces__srv__IsReady_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {jaime_interfaces__srv__IsReady_Event__TYPE_NAME, 34, 34},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
jaime_interfaces__srv__IsReady__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[6];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 6, 6};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *jaime_interfaces__srv__IsReady__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *jaime_interfaces__srv__IsReady_Event__get_individual_type_description_source(NULL);
    sources[3] = *jaime_interfaces__srv__IsReady_Request__get_individual_type_description_source(NULL);
    sources[4] = *jaime_interfaces__srv__IsReady_Response__get_individual_type_description_source(NULL);
    sources[5] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
jaime_interfaces__srv__IsReady_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *jaime_interfaces__srv__IsReady_Request__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
jaime_interfaces__srv__IsReady_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *jaime_interfaces__srv__IsReady_Response__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
jaime_interfaces__srv__IsReady_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[5];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 5, 5};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *jaime_interfaces__srv__IsReady_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *jaime_interfaces__srv__IsReady_Request__get_individual_type_description_source(NULL);
    sources[3] = *jaime_interfaces__srv__IsReady_Response__get_individual_type_description_source(NULL);
    sources[4] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
