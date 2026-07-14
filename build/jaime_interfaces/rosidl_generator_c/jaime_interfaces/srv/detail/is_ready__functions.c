// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from jaime_interfaces:srv/IsReady.idl
// generated code does not contain a copyright notice
#include "jaime_interfaces/srv/detail/is_ready__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
jaime_interfaces__srv__IsReady_Request__init(jaime_interfaces__srv__IsReady_Request * msg)
{
  if (!msg) {
    return false;
  }
  // structure_needs_at_least_one_member
  return true;
}

void
jaime_interfaces__srv__IsReady_Request__fini(jaime_interfaces__srv__IsReady_Request * msg)
{
  if (!msg) {
    return;
  }
  // structure_needs_at_least_one_member
}

bool
jaime_interfaces__srv__IsReady_Request__are_equal(const jaime_interfaces__srv__IsReady_Request * lhs, const jaime_interfaces__srv__IsReady_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // structure_needs_at_least_one_member
  if (lhs->structure_needs_at_least_one_member != rhs->structure_needs_at_least_one_member) {
    return false;
  }
  return true;
}

bool
jaime_interfaces__srv__IsReady_Request__copy(
  const jaime_interfaces__srv__IsReady_Request * input,
  jaime_interfaces__srv__IsReady_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // structure_needs_at_least_one_member
  output->structure_needs_at_least_one_member = input->structure_needs_at_least_one_member;
  return true;
}

jaime_interfaces__srv__IsReady_Request *
jaime_interfaces__srv__IsReady_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  jaime_interfaces__srv__IsReady_Request * msg = (jaime_interfaces__srv__IsReady_Request *)allocator.allocate(sizeof(jaime_interfaces__srv__IsReady_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(jaime_interfaces__srv__IsReady_Request));
  bool success = jaime_interfaces__srv__IsReady_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
jaime_interfaces__srv__IsReady_Request__destroy(jaime_interfaces__srv__IsReady_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    jaime_interfaces__srv__IsReady_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
jaime_interfaces__srv__IsReady_Request__Sequence__init(jaime_interfaces__srv__IsReady_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  jaime_interfaces__srv__IsReady_Request * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(jaime_interfaces__srv__IsReady_Request)) {
      return false;
    }
    data = (jaime_interfaces__srv__IsReady_Request *)allocator.zero_allocate(size, sizeof(jaime_interfaces__srv__IsReady_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = jaime_interfaces__srv__IsReady_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        jaime_interfaces__srv__IsReady_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
jaime_interfaces__srv__IsReady_Request__Sequence__fini(jaime_interfaces__srv__IsReady_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      jaime_interfaces__srv__IsReady_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

jaime_interfaces__srv__IsReady_Request__Sequence *
jaime_interfaces__srv__IsReady_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  jaime_interfaces__srv__IsReady_Request__Sequence * array = (jaime_interfaces__srv__IsReady_Request__Sequence *)allocator.allocate(sizeof(jaime_interfaces__srv__IsReady_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = jaime_interfaces__srv__IsReady_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
jaime_interfaces__srv__IsReady_Request__Sequence__destroy(jaime_interfaces__srv__IsReady_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    jaime_interfaces__srv__IsReady_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
jaime_interfaces__srv__IsReady_Request__Sequence__are_equal(const jaime_interfaces__srv__IsReady_Request__Sequence * lhs, const jaime_interfaces__srv__IsReady_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!jaime_interfaces__srv__IsReady_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
jaime_interfaces__srv__IsReady_Request__Sequence__copy(
  const jaime_interfaces__srv__IsReady_Request__Sequence * input,
  jaime_interfaces__srv__IsReady_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(jaime_interfaces__srv__IsReady_Request)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(jaime_interfaces__srv__IsReady_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    jaime_interfaces__srv__IsReady_Request * data =
      (jaime_interfaces__srv__IsReady_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!jaime_interfaces__srv__IsReady_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          jaime_interfaces__srv__IsReady_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!jaime_interfaces__srv__IsReady_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `message`
#include "rosidl_runtime_c/string_functions.h"

bool
jaime_interfaces__srv__IsReady_Response__init(jaime_interfaces__srv__IsReady_Response * msg)
{
  if (!msg) {
    return false;
  }
  // ready
  // message
  if (!rosidl_runtime_c__String__init(&msg->message)) {
    jaime_interfaces__srv__IsReady_Response__fini(msg);
    return false;
  }
  return true;
}

void
jaime_interfaces__srv__IsReady_Response__fini(jaime_interfaces__srv__IsReady_Response * msg)
{
  if (!msg) {
    return;
  }
  // ready
  // message
  rosidl_runtime_c__String__fini(&msg->message);
}

bool
jaime_interfaces__srv__IsReady_Response__are_equal(const jaime_interfaces__srv__IsReady_Response * lhs, const jaime_interfaces__srv__IsReady_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // ready
  if (lhs->ready != rhs->ready) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->message), &(rhs->message)))
  {
    return false;
  }
  return true;
}

bool
jaime_interfaces__srv__IsReady_Response__copy(
  const jaime_interfaces__srv__IsReady_Response * input,
  jaime_interfaces__srv__IsReady_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // ready
  output->ready = input->ready;
  // message
  if (!rosidl_runtime_c__String__copy(
      &(input->message), &(output->message)))
  {
    return false;
  }
  return true;
}

jaime_interfaces__srv__IsReady_Response *
jaime_interfaces__srv__IsReady_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  jaime_interfaces__srv__IsReady_Response * msg = (jaime_interfaces__srv__IsReady_Response *)allocator.allocate(sizeof(jaime_interfaces__srv__IsReady_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(jaime_interfaces__srv__IsReady_Response));
  bool success = jaime_interfaces__srv__IsReady_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
jaime_interfaces__srv__IsReady_Response__destroy(jaime_interfaces__srv__IsReady_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    jaime_interfaces__srv__IsReady_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
jaime_interfaces__srv__IsReady_Response__Sequence__init(jaime_interfaces__srv__IsReady_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  jaime_interfaces__srv__IsReady_Response * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(jaime_interfaces__srv__IsReady_Response)) {
      return false;
    }
    data = (jaime_interfaces__srv__IsReady_Response *)allocator.zero_allocate(size, sizeof(jaime_interfaces__srv__IsReady_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = jaime_interfaces__srv__IsReady_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        jaime_interfaces__srv__IsReady_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
jaime_interfaces__srv__IsReady_Response__Sequence__fini(jaime_interfaces__srv__IsReady_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      jaime_interfaces__srv__IsReady_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

jaime_interfaces__srv__IsReady_Response__Sequence *
jaime_interfaces__srv__IsReady_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  jaime_interfaces__srv__IsReady_Response__Sequence * array = (jaime_interfaces__srv__IsReady_Response__Sequence *)allocator.allocate(sizeof(jaime_interfaces__srv__IsReady_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = jaime_interfaces__srv__IsReady_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
jaime_interfaces__srv__IsReady_Response__Sequence__destroy(jaime_interfaces__srv__IsReady_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    jaime_interfaces__srv__IsReady_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
jaime_interfaces__srv__IsReady_Response__Sequence__are_equal(const jaime_interfaces__srv__IsReady_Response__Sequence * lhs, const jaime_interfaces__srv__IsReady_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!jaime_interfaces__srv__IsReady_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
jaime_interfaces__srv__IsReady_Response__Sequence__copy(
  const jaime_interfaces__srv__IsReady_Response__Sequence * input,
  jaime_interfaces__srv__IsReady_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(jaime_interfaces__srv__IsReady_Response)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(jaime_interfaces__srv__IsReady_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    jaime_interfaces__srv__IsReady_Response * data =
      (jaime_interfaces__srv__IsReady_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!jaime_interfaces__srv__IsReady_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          jaime_interfaces__srv__IsReady_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!jaime_interfaces__srv__IsReady_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `info`
#include "service_msgs/msg/detail/service_event_info__functions.h"
// Member `request`
// Member `response`
// already included above
// #include "jaime_interfaces/srv/detail/is_ready__functions.h"

bool
jaime_interfaces__srv__IsReady_Event__init(jaime_interfaces__srv__IsReady_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    jaime_interfaces__srv__IsReady_Event__fini(msg);
    return false;
  }
  // request
  if (!jaime_interfaces__srv__IsReady_Request__Sequence__init(&msg->request, 0)) {
    jaime_interfaces__srv__IsReady_Event__fini(msg);
    return false;
  }
  // response
  if (!jaime_interfaces__srv__IsReady_Response__Sequence__init(&msg->response, 0)) {
    jaime_interfaces__srv__IsReady_Event__fini(msg);
    return false;
  }
  return true;
}

void
jaime_interfaces__srv__IsReady_Event__fini(jaime_interfaces__srv__IsReady_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  jaime_interfaces__srv__IsReady_Request__Sequence__fini(&msg->request);
  // response
  jaime_interfaces__srv__IsReady_Response__Sequence__fini(&msg->response);
}

bool
jaime_interfaces__srv__IsReady_Event__are_equal(const jaime_interfaces__srv__IsReady_Event * lhs, const jaime_interfaces__srv__IsReady_Event * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__are_equal(
      &(lhs->info), &(rhs->info)))
  {
    return false;
  }
  // request
  if (!jaime_interfaces__srv__IsReady_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!jaime_interfaces__srv__IsReady_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
jaime_interfaces__srv__IsReady_Event__copy(
  const jaime_interfaces__srv__IsReady_Event * input,
  jaime_interfaces__srv__IsReady_Event * output)
{
  if (!input || !output) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__copy(
      &(input->info), &(output->info)))
  {
    return false;
  }
  // request
  if (!jaime_interfaces__srv__IsReady_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!jaime_interfaces__srv__IsReady_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

jaime_interfaces__srv__IsReady_Event *
jaime_interfaces__srv__IsReady_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  jaime_interfaces__srv__IsReady_Event * msg = (jaime_interfaces__srv__IsReady_Event *)allocator.allocate(sizeof(jaime_interfaces__srv__IsReady_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(jaime_interfaces__srv__IsReady_Event));
  bool success = jaime_interfaces__srv__IsReady_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
jaime_interfaces__srv__IsReady_Event__destroy(jaime_interfaces__srv__IsReady_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    jaime_interfaces__srv__IsReady_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
jaime_interfaces__srv__IsReady_Event__Sequence__init(jaime_interfaces__srv__IsReady_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  jaime_interfaces__srv__IsReady_Event * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(jaime_interfaces__srv__IsReady_Event)) {
      return false;
    }
    data = (jaime_interfaces__srv__IsReady_Event *)allocator.zero_allocate(size, sizeof(jaime_interfaces__srv__IsReady_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = jaime_interfaces__srv__IsReady_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        jaime_interfaces__srv__IsReady_Event__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
jaime_interfaces__srv__IsReady_Event__Sequence__fini(jaime_interfaces__srv__IsReady_Event__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      jaime_interfaces__srv__IsReady_Event__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

jaime_interfaces__srv__IsReady_Event__Sequence *
jaime_interfaces__srv__IsReady_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  jaime_interfaces__srv__IsReady_Event__Sequence * array = (jaime_interfaces__srv__IsReady_Event__Sequence *)allocator.allocate(sizeof(jaime_interfaces__srv__IsReady_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = jaime_interfaces__srv__IsReady_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
jaime_interfaces__srv__IsReady_Event__Sequence__destroy(jaime_interfaces__srv__IsReady_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    jaime_interfaces__srv__IsReady_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
jaime_interfaces__srv__IsReady_Event__Sequence__are_equal(const jaime_interfaces__srv__IsReady_Event__Sequence * lhs, const jaime_interfaces__srv__IsReady_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!jaime_interfaces__srv__IsReady_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
jaime_interfaces__srv__IsReady_Event__Sequence__copy(
  const jaime_interfaces__srv__IsReady_Event__Sequence * input,
  jaime_interfaces__srv__IsReady_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(jaime_interfaces__srv__IsReady_Event)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(jaime_interfaces__srv__IsReady_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    jaime_interfaces__srv__IsReady_Event * data =
      (jaime_interfaces__srv__IsReady_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!jaime_interfaces__srv__IsReady_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          jaime_interfaces__srv__IsReady_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!jaime_interfaces__srv__IsReady_Event__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
