// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from jaime_interfaces:action/MoveToPose.idl
// generated code does not contain a copyright notice
#include "jaime_interfaces/action/detail/move_to_pose__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `target_position`
#include "geometry_msgs/msg/detail/point__functions.h"

bool
jaime_interfaces__action__MoveToPose_Goal__init(jaime_interfaces__action__MoveToPose_Goal * msg)
{
  if (!msg) {
    return false;
  }
  // target_position
  if (!geometry_msgs__msg__Point__init(&msg->target_position)) {
    jaime_interfaces__action__MoveToPose_Goal__fini(msg);
    return false;
  }
  return true;
}

void
jaime_interfaces__action__MoveToPose_Goal__fini(jaime_interfaces__action__MoveToPose_Goal * msg)
{
  if (!msg) {
    return;
  }
  // target_position
  geometry_msgs__msg__Point__fini(&msg->target_position);
}

bool
jaime_interfaces__action__MoveToPose_Goal__are_equal(const jaime_interfaces__action__MoveToPose_Goal * lhs, const jaime_interfaces__action__MoveToPose_Goal * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // target_position
  if (!geometry_msgs__msg__Point__are_equal(
      &(lhs->target_position), &(rhs->target_position)))
  {
    return false;
  }
  return true;
}

bool
jaime_interfaces__action__MoveToPose_Goal__copy(
  const jaime_interfaces__action__MoveToPose_Goal * input,
  jaime_interfaces__action__MoveToPose_Goal * output)
{
  if (!input || !output) {
    return false;
  }
  // target_position
  if (!geometry_msgs__msg__Point__copy(
      &(input->target_position), &(output->target_position)))
  {
    return false;
  }
  return true;
}

jaime_interfaces__action__MoveToPose_Goal *
jaime_interfaces__action__MoveToPose_Goal__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  jaime_interfaces__action__MoveToPose_Goal * msg = (jaime_interfaces__action__MoveToPose_Goal *)allocator.allocate(sizeof(jaime_interfaces__action__MoveToPose_Goal), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(jaime_interfaces__action__MoveToPose_Goal));
  bool success = jaime_interfaces__action__MoveToPose_Goal__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
jaime_interfaces__action__MoveToPose_Goal__destroy(jaime_interfaces__action__MoveToPose_Goal * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    jaime_interfaces__action__MoveToPose_Goal__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
jaime_interfaces__action__MoveToPose_Goal__Sequence__init(jaime_interfaces__action__MoveToPose_Goal__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  jaime_interfaces__action__MoveToPose_Goal * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(jaime_interfaces__action__MoveToPose_Goal)) {
      return false;
    }
    data = (jaime_interfaces__action__MoveToPose_Goal *)allocator.zero_allocate(size, sizeof(jaime_interfaces__action__MoveToPose_Goal), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = jaime_interfaces__action__MoveToPose_Goal__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        jaime_interfaces__action__MoveToPose_Goal__fini(&data[i - 1]);
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
jaime_interfaces__action__MoveToPose_Goal__Sequence__fini(jaime_interfaces__action__MoveToPose_Goal__Sequence * array)
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
      jaime_interfaces__action__MoveToPose_Goal__fini(&array->data[i]);
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

jaime_interfaces__action__MoveToPose_Goal__Sequence *
jaime_interfaces__action__MoveToPose_Goal__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  jaime_interfaces__action__MoveToPose_Goal__Sequence * array = (jaime_interfaces__action__MoveToPose_Goal__Sequence *)allocator.allocate(sizeof(jaime_interfaces__action__MoveToPose_Goal__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = jaime_interfaces__action__MoveToPose_Goal__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
jaime_interfaces__action__MoveToPose_Goal__Sequence__destroy(jaime_interfaces__action__MoveToPose_Goal__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    jaime_interfaces__action__MoveToPose_Goal__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
jaime_interfaces__action__MoveToPose_Goal__Sequence__are_equal(const jaime_interfaces__action__MoveToPose_Goal__Sequence * lhs, const jaime_interfaces__action__MoveToPose_Goal__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!jaime_interfaces__action__MoveToPose_Goal__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
jaime_interfaces__action__MoveToPose_Goal__Sequence__copy(
  const jaime_interfaces__action__MoveToPose_Goal__Sequence * input,
  jaime_interfaces__action__MoveToPose_Goal__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(jaime_interfaces__action__MoveToPose_Goal)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(jaime_interfaces__action__MoveToPose_Goal);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    jaime_interfaces__action__MoveToPose_Goal * data =
      (jaime_interfaces__action__MoveToPose_Goal *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!jaime_interfaces__action__MoveToPose_Goal__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          jaime_interfaces__action__MoveToPose_Goal__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!jaime_interfaces__action__MoveToPose_Goal__copy(
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
jaime_interfaces__action__MoveToPose_Result__init(jaime_interfaces__action__MoveToPose_Result * msg)
{
  if (!msg) {
    return false;
  }
  // success
  // message
  if (!rosidl_runtime_c__String__init(&msg->message)) {
    jaime_interfaces__action__MoveToPose_Result__fini(msg);
    return false;
  }
  return true;
}

void
jaime_interfaces__action__MoveToPose_Result__fini(jaime_interfaces__action__MoveToPose_Result * msg)
{
  if (!msg) {
    return;
  }
  // success
  // message
  rosidl_runtime_c__String__fini(&msg->message);
}

bool
jaime_interfaces__action__MoveToPose_Result__are_equal(const jaime_interfaces__action__MoveToPose_Result * lhs, const jaime_interfaces__action__MoveToPose_Result * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
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
jaime_interfaces__action__MoveToPose_Result__copy(
  const jaime_interfaces__action__MoveToPose_Result * input,
  jaime_interfaces__action__MoveToPose_Result * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  // message
  if (!rosidl_runtime_c__String__copy(
      &(input->message), &(output->message)))
  {
    return false;
  }
  return true;
}

jaime_interfaces__action__MoveToPose_Result *
jaime_interfaces__action__MoveToPose_Result__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  jaime_interfaces__action__MoveToPose_Result * msg = (jaime_interfaces__action__MoveToPose_Result *)allocator.allocate(sizeof(jaime_interfaces__action__MoveToPose_Result), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(jaime_interfaces__action__MoveToPose_Result));
  bool success = jaime_interfaces__action__MoveToPose_Result__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
jaime_interfaces__action__MoveToPose_Result__destroy(jaime_interfaces__action__MoveToPose_Result * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    jaime_interfaces__action__MoveToPose_Result__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
jaime_interfaces__action__MoveToPose_Result__Sequence__init(jaime_interfaces__action__MoveToPose_Result__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  jaime_interfaces__action__MoveToPose_Result * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(jaime_interfaces__action__MoveToPose_Result)) {
      return false;
    }
    data = (jaime_interfaces__action__MoveToPose_Result *)allocator.zero_allocate(size, sizeof(jaime_interfaces__action__MoveToPose_Result), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = jaime_interfaces__action__MoveToPose_Result__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        jaime_interfaces__action__MoveToPose_Result__fini(&data[i - 1]);
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
jaime_interfaces__action__MoveToPose_Result__Sequence__fini(jaime_interfaces__action__MoveToPose_Result__Sequence * array)
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
      jaime_interfaces__action__MoveToPose_Result__fini(&array->data[i]);
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

jaime_interfaces__action__MoveToPose_Result__Sequence *
jaime_interfaces__action__MoveToPose_Result__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  jaime_interfaces__action__MoveToPose_Result__Sequence * array = (jaime_interfaces__action__MoveToPose_Result__Sequence *)allocator.allocate(sizeof(jaime_interfaces__action__MoveToPose_Result__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = jaime_interfaces__action__MoveToPose_Result__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
jaime_interfaces__action__MoveToPose_Result__Sequence__destroy(jaime_interfaces__action__MoveToPose_Result__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    jaime_interfaces__action__MoveToPose_Result__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
jaime_interfaces__action__MoveToPose_Result__Sequence__are_equal(const jaime_interfaces__action__MoveToPose_Result__Sequence * lhs, const jaime_interfaces__action__MoveToPose_Result__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!jaime_interfaces__action__MoveToPose_Result__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
jaime_interfaces__action__MoveToPose_Result__Sequence__copy(
  const jaime_interfaces__action__MoveToPose_Result__Sequence * input,
  jaime_interfaces__action__MoveToPose_Result__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(jaime_interfaces__action__MoveToPose_Result)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(jaime_interfaces__action__MoveToPose_Result);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    jaime_interfaces__action__MoveToPose_Result * data =
      (jaime_interfaces__action__MoveToPose_Result *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!jaime_interfaces__action__MoveToPose_Result__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          jaime_interfaces__action__MoveToPose_Result__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!jaime_interfaces__action__MoveToPose_Result__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
jaime_interfaces__action__MoveToPose_Feedback__init(jaime_interfaces__action__MoveToPose_Feedback * msg)
{
  if (!msg) {
    return false;
  }
  // error
  return true;
}

void
jaime_interfaces__action__MoveToPose_Feedback__fini(jaime_interfaces__action__MoveToPose_Feedback * msg)
{
  if (!msg) {
    return;
  }
  // error
}

bool
jaime_interfaces__action__MoveToPose_Feedback__are_equal(const jaime_interfaces__action__MoveToPose_Feedback * lhs, const jaime_interfaces__action__MoveToPose_Feedback * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // error
  if (lhs->error != rhs->error) {
    return false;
  }
  return true;
}

bool
jaime_interfaces__action__MoveToPose_Feedback__copy(
  const jaime_interfaces__action__MoveToPose_Feedback * input,
  jaime_interfaces__action__MoveToPose_Feedback * output)
{
  if (!input || !output) {
    return false;
  }
  // error
  output->error = input->error;
  return true;
}

jaime_interfaces__action__MoveToPose_Feedback *
jaime_interfaces__action__MoveToPose_Feedback__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  jaime_interfaces__action__MoveToPose_Feedback * msg = (jaime_interfaces__action__MoveToPose_Feedback *)allocator.allocate(sizeof(jaime_interfaces__action__MoveToPose_Feedback), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(jaime_interfaces__action__MoveToPose_Feedback));
  bool success = jaime_interfaces__action__MoveToPose_Feedback__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
jaime_interfaces__action__MoveToPose_Feedback__destroy(jaime_interfaces__action__MoveToPose_Feedback * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    jaime_interfaces__action__MoveToPose_Feedback__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
jaime_interfaces__action__MoveToPose_Feedback__Sequence__init(jaime_interfaces__action__MoveToPose_Feedback__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  jaime_interfaces__action__MoveToPose_Feedback * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(jaime_interfaces__action__MoveToPose_Feedback)) {
      return false;
    }
    data = (jaime_interfaces__action__MoveToPose_Feedback *)allocator.zero_allocate(size, sizeof(jaime_interfaces__action__MoveToPose_Feedback), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = jaime_interfaces__action__MoveToPose_Feedback__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        jaime_interfaces__action__MoveToPose_Feedback__fini(&data[i - 1]);
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
jaime_interfaces__action__MoveToPose_Feedback__Sequence__fini(jaime_interfaces__action__MoveToPose_Feedback__Sequence * array)
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
      jaime_interfaces__action__MoveToPose_Feedback__fini(&array->data[i]);
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

jaime_interfaces__action__MoveToPose_Feedback__Sequence *
jaime_interfaces__action__MoveToPose_Feedback__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  jaime_interfaces__action__MoveToPose_Feedback__Sequence * array = (jaime_interfaces__action__MoveToPose_Feedback__Sequence *)allocator.allocate(sizeof(jaime_interfaces__action__MoveToPose_Feedback__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = jaime_interfaces__action__MoveToPose_Feedback__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
jaime_interfaces__action__MoveToPose_Feedback__Sequence__destroy(jaime_interfaces__action__MoveToPose_Feedback__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    jaime_interfaces__action__MoveToPose_Feedback__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
jaime_interfaces__action__MoveToPose_Feedback__Sequence__are_equal(const jaime_interfaces__action__MoveToPose_Feedback__Sequence * lhs, const jaime_interfaces__action__MoveToPose_Feedback__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!jaime_interfaces__action__MoveToPose_Feedback__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
jaime_interfaces__action__MoveToPose_Feedback__Sequence__copy(
  const jaime_interfaces__action__MoveToPose_Feedback__Sequence * input,
  jaime_interfaces__action__MoveToPose_Feedback__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(jaime_interfaces__action__MoveToPose_Feedback)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(jaime_interfaces__action__MoveToPose_Feedback);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    jaime_interfaces__action__MoveToPose_Feedback * data =
      (jaime_interfaces__action__MoveToPose_Feedback *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!jaime_interfaces__action__MoveToPose_Feedback__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          jaime_interfaces__action__MoveToPose_Feedback__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!jaime_interfaces__action__MoveToPose_Feedback__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
#include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `goal`
// already included above
// #include "jaime_interfaces/action/detail/move_to_pose__functions.h"

bool
jaime_interfaces__action__MoveToPose_SendGoal_Request__init(jaime_interfaces__action__MoveToPose_SendGoal_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    jaime_interfaces__action__MoveToPose_SendGoal_Request__fini(msg);
    return false;
  }
  // goal
  if (!jaime_interfaces__action__MoveToPose_Goal__init(&msg->goal)) {
    jaime_interfaces__action__MoveToPose_SendGoal_Request__fini(msg);
    return false;
  }
  return true;
}

void
jaime_interfaces__action__MoveToPose_SendGoal_Request__fini(jaime_interfaces__action__MoveToPose_SendGoal_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // goal
  jaime_interfaces__action__MoveToPose_Goal__fini(&msg->goal);
}

bool
jaime_interfaces__action__MoveToPose_SendGoal_Request__are_equal(const jaime_interfaces__action__MoveToPose_SendGoal_Request * lhs, const jaime_interfaces__action__MoveToPose_SendGoal_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // goal
  if (!jaime_interfaces__action__MoveToPose_Goal__are_equal(
      &(lhs->goal), &(rhs->goal)))
  {
    return false;
  }
  return true;
}

bool
jaime_interfaces__action__MoveToPose_SendGoal_Request__copy(
  const jaime_interfaces__action__MoveToPose_SendGoal_Request * input,
  jaime_interfaces__action__MoveToPose_SendGoal_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // goal
  if (!jaime_interfaces__action__MoveToPose_Goal__copy(
      &(input->goal), &(output->goal)))
  {
    return false;
  }
  return true;
}

jaime_interfaces__action__MoveToPose_SendGoal_Request *
jaime_interfaces__action__MoveToPose_SendGoal_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  jaime_interfaces__action__MoveToPose_SendGoal_Request * msg = (jaime_interfaces__action__MoveToPose_SendGoal_Request *)allocator.allocate(sizeof(jaime_interfaces__action__MoveToPose_SendGoal_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(jaime_interfaces__action__MoveToPose_SendGoal_Request));
  bool success = jaime_interfaces__action__MoveToPose_SendGoal_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
jaime_interfaces__action__MoveToPose_SendGoal_Request__destroy(jaime_interfaces__action__MoveToPose_SendGoal_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    jaime_interfaces__action__MoveToPose_SendGoal_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
jaime_interfaces__action__MoveToPose_SendGoal_Request__Sequence__init(jaime_interfaces__action__MoveToPose_SendGoal_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  jaime_interfaces__action__MoveToPose_SendGoal_Request * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(jaime_interfaces__action__MoveToPose_SendGoal_Request)) {
      return false;
    }
    data = (jaime_interfaces__action__MoveToPose_SendGoal_Request *)allocator.zero_allocate(size, sizeof(jaime_interfaces__action__MoveToPose_SendGoal_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = jaime_interfaces__action__MoveToPose_SendGoal_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        jaime_interfaces__action__MoveToPose_SendGoal_Request__fini(&data[i - 1]);
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
jaime_interfaces__action__MoveToPose_SendGoal_Request__Sequence__fini(jaime_interfaces__action__MoveToPose_SendGoal_Request__Sequence * array)
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
      jaime_interfaces__action__MoveToPose_SendGoal_Request__fini(&array->data[i]);
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

jaime_interfaces__action__MoveToPose_SendGoal_Request__Sequence *
jaime_interfaces__action__MoveToPose_SendGoal_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  jaime_interfaces__action__MoveToPose_SendGoal_Request__Sequence * array = (jaime_interfaces__action__MoveToPose_SendGoal_Request__Sequence *)allocator.allocate(sizeof(jaime_interfaces__action__MoveToPose_SendGoal_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = jaime_interfaces__action__MoveToPose_SendGoal_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
jaime_interfaces__action__MoveToPose_SendGoal_Request__Sequence__destroy(jaime_interfaces__action__MoveToPose_SendGoal_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    jaime_interfaces__action__MoveToPose_SendGoal_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
jaime_interfaces__action__MoveToPose_SendGoal_Request__Sequence__are_equal(const jaime_interfaces__action__MoveToPose_SendGoal_Request__Sequence * lhs, const jaime_interfaces__action__MoveToPose_SendGoal_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!jaime_interfaces__action__MoveToPose_SendGoal_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
jaime_interfaces__action__MoveToPose_SendGoal_Request__Sequence__copy(
  const jaime_interfaces__action__MoveToPose_SendGoal_Request__Sequence * input,
  jaime_interfaces__action__MoveToPose_SendGoal_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(jaime_interfaces__action__MoveToPose_SendGoal_Request)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(jaime_interfaces__action__MoveToPose_SendGoal_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    jaime_interfaces__action__MoveToPose_SendGoal_Request * data =
      (jaime_interfaces__action__MoveToPose_SendGoal_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!jaime_interfaces__action__MoveToPose_SendGoal_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          jaime_interfaces__action__MoveToPose_SendGoal_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!jaime_interfaces__action__MoveToPose_SendGoal_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
jaime_interfaces__action__MoveToPose_SendGoal_Response__init(jaime_interfaces__action__MoveToPose_SendGoal_Response * msg)
{
  if (!msg) {
    return false;
  }
  // accepted
  // stamp
  if (!builtin_interfaces__msg__Time__init(&msg->stamp)) {
    jaime_interfaces__action__MoveToPose_SendGoal_Response__fini(msg);
    return false;
  }
  return true;
}

void
jaime_interfaces__action__MoveToPose_SendGoal_Response__fini(jaime_interfaces__action__MoveToPose_SendGoal_Response * msg)
{
  if (!msg) {
    return;
  }
  // accepted
  // stamp
  builtin_interfaces__msg__Time__fini(&msg->stamp);
}

bool
jaime_interfaces__action__MoveToPose_SendGoal_Response__are_equal(const jaime_interfaces__action__MoveToPose_SendGoal_Response * lhs, const jaime_interfaces__action__MoveToPose_SendGoal_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // accepted
  if (lhs->accepted != rhs->accepted) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->stamp), &(rhs->stamp)))
  {
    return false;
  }
  return true;
}

bool
jaime_interfaces__action__MoveToPose_SendGoal_Response__copy(
  const jaime_interfaces__action__MoveToPose_SendGoal_Response * input,
  jaime_interfaces__action__MoveToPose_SendGoal_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // accepted
  output->accepted = input->accepted;
  // stamp
  if (!builtin_interfaces__msg__Time__copy(
      &(input->stamp), &(output->stamp)))
  {
    return false;
  }
  return true;
}

jaime_interfaces__action__MoveToPose_SendGoal_Response *
jaime_interfaces__action__MoveToPose_SendGoal_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  jaime_interfaces__action__MoveToPose_SendGoal_Response * msg = (jaime_interfaces__action__MoveToPose_SendGoal_Response *)allocator.allocate(sizeof(jaime_interfaces__action__MoveToPose_SendGoal_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(jaime_interfaces__action__MoveToPose_SendGoal_Response));
  bool success = jaime_interfaces__action__MoveToPose_SendGoal_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
jaime_interfaces__action__MoveToPose_SendGoal_Response__destroy(jaime_interfaces__action__MoveToPose_SendGoal_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    jaime_interfaces__action__MoveToPose_SendGoal_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
jaime_interfaces__action__MoveToPose_SendGoal_Response__Sequence__init(jaime_interfaces__action__MoveToPose_SendGoal_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  jaime_interfaces__action__MoveToPose_SendGoal_Response * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(jaime_interfaces__action__MoveToPose_SendGoal_Response)) {
      return false;
    }
    data = (jaime_interfaces__action__MoveToPose_SendGoal_Response *)allocator.zero_allocate(size, sizeof(jaime_interfaces__action__MoveToPose_SendGoal_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = jaime_interfaces__action__MoveToPose_SendGoal_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        jaime_interfaces__action__MoveToPose_SendGoal_Response__fini(&data[i - 1]);
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
jaime_interfaces__action__MoveToPose_SendGoal_Response__Sequence__fini(jaime_interfaces__action__MoveToPose_SendGoal_Response__Sequence * array)
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
      jaime_interfaces__action__MoveToPose_SendGoal_Response__fini(&array->data[i]);
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

jaime_interfaces__action__MoveToPose_SendGoal_Response__Sequence *
jaime_interfaces__action__MoveToPose_SendGoal_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  jaime_interfaces__action__MoveToPose_SendGoal_Response__Sequence * array = (jaime_interfaces__action__MoveToPose_SendGoal_Response__Sequence *)allocator.allocate(sizeof(jaime_interfaces__action__MoveToPose_SendGoal_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = jaime_interfaces__action__MoveToPose_SendGoal_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
jaime_interfaces__action__MoveToPose_SendGoal_Response__Sequence__destroy(jaime_interfaces__action__MoveToPose_SendGoal_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    jaime_interfaces__action__MoveToPose_SendGoal_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
jaime_interfaces__action__MoveToPose_SendGoal_Response__Sequence__are_equal(const jaime_interfaces__action__MoveToPose_SendGoal_Response__Sequence * lhs, const jaime_interfaces__action__MoveToPose_SendGoal_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!jaime_interfaces__action__MoveToPose_SendGoal_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
jaime_interfaces__action__MoveToPose_SendGoal_Response__Sequence__copy(
  const jaime_interfaces__action__MoveToPose_SendGoal_Response__Sequence * input,
  jaime_interfaces__action__MoveToPose_SendGoal_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(jaime_interfaces__action__MoveToPose_SendGoal_Response)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(jaime_interfaces__action__MoveToPose_SendGoal_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    jaime_interfaces__action__MoveToPose_SendGoal_Response * data =
      (jaime_interfaces__action__MoveToPose_SendGoal_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!jaime_interfaces__action__MoveToPose_SendGoal_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          jaime_interfaces__action__MoveToPose_SendGoal_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!jaime_interfaces__action__MoveToPose_SendGoal_Response__copy(
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
// #include "jaime_interfaces/action/detail/move_to_pose__functions.h"

bool
jaime_interfaces__action__MoveToPose_SendGoal_Event__init(jaime_interfaces__action__MoveToPose_SendGoal_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    jaime_interfaces__action__MoveToPose_SendGoal_Event__fini(msg);
    return false;
  }
  // request
  if (!jaime_interfaces__action__MoveToPose_SendGoal_Request__Sequence__init(&msg->request, 0)) {
    jaime_interfaces__action__MoveToPose_SendGoal_Event__fini(msg);
    return false;
  }
  // response
  if (!jaime_interfaces__action__MoveToPose_SendGoal_Response__Sequence__init(&msg->response, 0)) {
    jaime_interfaces__action__MoveToPose_SendGoal_Event__fini(msg);
    return false;
  }
  return true;
}

void
jaime_interfaces__action__MoveToPose_SendGoal_Event__fini(jaime_interfaces__action__MoveToPose_SendGoal_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  jaime_interfaces__action__MoveToPose_SendGoal_Request__Sequence__fini(&msg->request);
  // response
  jaime_interfaces__action__MoveToPose_SendGoal_Response__Sequence__fini(&msg->response);
}

bool
jaime_interfaces__action__MoveToPose_SendGoal_Event__are_equal(const jaime_interfaces__action__MoveToPose_SendGoal_Event * lhs, const jaime_interfaces__action__MoveToPose_SendGoal_Event * rhs)
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
  if (!jaime_interfaces__action__MoveToPose_SendGoal_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!jaime_interfaces__action__MoveToPose_SendGoal_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
jaime_interfaces__action__MoveToPose_SendGoal_Event__copy(
  const jaime_interfaces__action__MoveToPose_SendGoal_Event * input,
  jaime_interfaces__action__MoveToPose_SendGoal_Event * output)
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
  if (!jaime_interfaces__action__MoveToPose_SendGoal_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!jaime_interfaces__action__MoveToPose_SendGoal_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

jaime_interfaces__action__MoveToPose_SendGoal_Event *
jaime_interfaces__action__MoveToPose_SendGoal_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  jaime_interfaces__action__MoveToPose_SendGoal_Event * msg = (jaime_interfaces__action__MoveToPose_SendGoal_Event *)allocator.allocate(sizeof(jaime_interfaces__action__MoveToPose_SendGoal_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(jaime_interfaces__action__MoveToPose_SendGoal_Event));
  bool success = jaime_interfaces__action__MoveToPose_SendGoal_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
jaime_interfaces__action__MoveToPose_SendGoal_Event__destroy(jaime_interfaces__action__MoveToPose_SendGoal_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    jaime_interfaces__action__MoveToPose_SendGoal_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
jaime_interfaces__action__MoveToPose_SendGoal_Event__Sequence__init(jaime_interfaces__action__MoveToPose_SendGoal_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  jaime_interfaces__action__MoveToPose_SendGoal_Event * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(jaime_interfaces__action__MoveToPose_SendGoal_Event)) {
      return false;
    }
    data = (jaime_interfaces__action__MoveToPose_SendGoal_Event *)allocator.zero_allocate(size, sizeof(jaime_interfaces__action__MoveToPose_SendGoal_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = jaime_interfaces__action__MoveToPose_SendGoal_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        jaime_interfaces__action__MoveToPose_SendGoal_Event__fini(&data[i - 1]);
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
jaime_interfaces__action__MoveToPose_SendGoal_Event__Sequence__fini(jaime_interfaces__action__MoveToPose_SendGoal_Event__Sequence * array)
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
      jaime_interfaces__action__MoveToPose_SendGoal_Event__fini(&array->data[i]);
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

jaime_interfaces__action__MoveToPose_SendGoal_Event__Sequence *
jaime_interfaces__action__MoveToPose_SendGoal_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  jaime_interfaces__action__MoveToPose_SendGoal_Event__Sequence * array = (jaime_interfaces__action__MoveToPose_SendGoal_Event__Sequence *)allocator.allocate(sizeof(jaime_interfaces__action__MoveToPose_SendGoal_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = jaime_interfaces__action__MoveToPose_SendGoal_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
jaime_interfaces__action__MoveToPose_SendGoal_Event__Sequence__destroy(jaime_interfaces__action__MoveToPose_SendGoal_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    jaime_interfaces__action__MoveToPose_SendGoal_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
jaime_interfaces__action__MoveToPose_SendGoal_Event__Sequence__are_equal(const jaime_interfaces__action__MoveToPose_SendGoal_Event__Sequence * lhs, const jaime_interfaces__action__MoveToPose_SendGoal_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!jaime_interfaces__action__MoveToPose_SendGoal_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
jaime_interfaces__action__MoveToPose_SendGoal_Event__Sequence__copy(
  const jaime_interfaces__action__MoveToPose_SendGoal_Event__Sequence * input,
  jaime_interfaces__action__MoveToPose_SendGoal_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(jaime_interfaces__action__MoveToPose_SendGoal_Event)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(jaime_interfaces__action__MoveToPose_SendGoal_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    jaime_interfaces__action__MoveToPose_SendGoal_Event * data =
      (jaime_interfaces__action__MoveToPose_SendGoal_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!jaime_interfaces__action__MoveToPose_SendGoal_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          jaime_interfaces__action__MoveToPose_SendGoal_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!jaime_interfaces__action__MoveToPose_SendGoal_Event__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"

bool
jaime_interfaces__action__MoveToPose_GetResult_Request__init(jaime_interfaces__action__MoveToPose_GetResult_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    jaime_interfaces__action__MoveToPose_GetResult_Request__fini(msg);
    return false;
  }
  return true;
}

void
jaime_interfaces__action__MoveToPose_GetResult_Request__fini(jaime_interfaces__action__MoveToPose_GetResult_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
}

bool
jaime_interfaces__action__MoveToPose_GetResult_Request__are_equal(const jaime_interfaces__action__MoveToPose_GetResult_Request * lhs, const jaime_interfaces__action__MoveToPose_GetResult_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  return true;
}

bool
jaime_interfaces__action__MoveToPose_GetResult_Request__copy(
  const jaime_interfaces__action__MoveToPose_GetResult_Request * input,
  jaime_interfaces__action__MoveToPose_GetResult_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  return true;
}

jaime_interfaces__action__MoveToPose_GetResult_Request *
jaime_interfaces__action__MoveToPose_GetResult_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  jaime_interfaces__action__MoveToPose_GetResult_Request * msg = (jaime_interfaces__action__MoveToPose_GetResult_Request *)allocator.allocate(sizeof(jaime_interfaces__action__MoveToPose_GetResult_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(jaime_interfaces__action__MoveToPose_GetResult_Request));
  bool success = jaime_interfaces__action__MoveToPose_GetResult_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
jaime_interfaces__action__MoveToPose_GetResult_Request__destroy(jaime_interfaces__action__MoveToPose_GetResult_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    jaime_interfaces__action__MoveToPose_GetResult_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
jaime_interfaces__action__MoveToPose_GetResult_Request__Sequence__init(jaime_interfaces__action__MoveToPose_GetResult_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  jaime_interfaces__action__MoveToPose_GetResult_Request * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(jaime_interfaces__action__MoveToPose_GetResult_Request)) {
      return false;
    }
    data = (jaime_interfaces__action__MoveToPose_GetResult_Request *)allocator.zero_allocate(size, sizeof(jaime_interfaces__action__MoveToPose_GetResult_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = jaime_interfaces__action__MoveToPose_GetResult_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        jaime_interfaces__action__MoveToPose_GetResult_Request__fini(&data[i - 1]);
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
jaime_interfaces__action__MoveToPose_GetResult_Request__Sequence__fini(jaime_interfaces__action__MoveToPose_GetResult_Request__Sequence * array)
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
      jaime_interfaces__action__MoveToPose_GetResult_Request__fini(&array->data[i]);
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

jaime_interfaces__action__MoveToPose_GetResult_Request__Sequence *
jaime_interfaces__action__MoveToPose_GetResult_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  jaime_interfaces__action__MoveToPose_GetResult_Request__Sequence * array = (jaime_interfaces__action__MoveToPose_GetResult_Request__Sequence *)allocator.allocate(sizeof(jaime_interfaces__action__MoveToPose_GetResult_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = jaime_interfaces__action__MoveToPose_GetResult_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
jaime_interfaces__action__MoveToPose_GetResult_Request__Sequence__destroy(jaime_interfaces__action__MoveToPose_GetResult_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    jaime_interfaces__action__MoveToPose_GetResult_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
jaime_interfaces__action__MoveToPose_GetResult_Request__Sequence__are_equal(const jaime_interfaces__action__MoveToPose_GetResult_Request__Sequence * lhs, const jaime_interfaces__action__MoveToPose_GetResult_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!jaime_interfaces__action__MoveToPose_GetResult_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
jaime_interfaces__action__MoveToPose_GetResult_Request__Sequence__copy(
  const jaime_interfaces__action__MoveToPose_GetResult_Request__Sequence * input,
  jaime_interfaces__action__MoveToPose_GetResult_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(jaime_interfaces__action__MoveToPose_GetResult_Request)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(jaime_interfaces__action__MoveToPose_GetResult_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    jaime_interfaces__action__MoveToPose_GetResult_Request * data =
      (jaime_interfaces__action__MoveToPose_GetResult_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!jaime_interfaces__action__MoveToPose_GetResult_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          jaime_interfaces__action__MoveToPose_GetResult_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!jaime_interfaces__action__MoveToPose_GetResult_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `result`
// already included above
// #include "jaime_interfaces/action/detail/move_to_pose__functions.h"

bool
jaime_interfaces__action__MoveToPose_GetResult_Response__init(jaime_interfaces__action__MoveToPose_GetResult_Response * msg)
{
  if (!msg) {
    return false;
  }
  // status
  // result
  if (!jaime_interfaces__action__MoveToPose_Result__init(&msg->result)) {
    jaime_interfaces__action__MoveToPose_GetResult_Response__fini(msg);
    return false;
  }
  return true;
}

void
jaime_interfaces__action__MoveToPose_GetResult_Response__fini(jaime_interfaces__action__MoveToPose_GetResult_Response * msg)
{
  if (!msg) {
    return;
  }
  // status
  // result
  jaime_interfaces__action__MoveToPose_Result__fini(&msg->result);
}

bool
jaime_interfaces__action__MoveToPose_GetResult_Response__are_equal(const jaime_interfaces__action__MoveToPose_GetResult_Response * lhs, const jaime_interfaces__action__MoveToPose_GetResult_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // status
  if (lhs->status != rhs->status) {
    return false;
  }
  // result
  if (!jaime_interfaces__action__MoveToPose_Result__are_equal(
      &(lhs->result), &(rhs->result)))
  {
    return false;
  }
  return true;
}

bool
jaime_interfaces__action__MoveToPose_GetResult_Response__copy(
  const jaime_interfaces__action__MoveToPose_GetResult_Response * input,
  jaime_interfaces__action__MoveToPose_GetResult_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // status
  output->status = input->status;
  // result
  if (!jaime_interfaces__action__MoveToPose_Result__copy(
      &(input->result), &(output->result)))
  {
    return false;
  }
  return true;
}

jaime_interfaces__action__MoveToPose_GetResult_Response *
jaime_interfaces__action__MoveToPose_GetResult_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  jaime_interfaces__action__MoveToPose_GetResult_Response * msg = (jaime_interfaces__action__MoveToPose_GetResult_Response *)allocator.allocate(sizeof(jaime_interfaces__action__MoveToPose_GetResult_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(jaime_interfaces__action__MoveToPose_GetResult_Response));
  bool success = jaime_interfaces__action__MoveToPose_GetResult_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
jaime_interfaces__action__MoveToPose_GetResult_Response__destroy(jaime_interfaces__action__MoveToPose_GetResult_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    jaime_interfaces__action__MoveToPose_GetResult_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
jaime_interfaces__action__MoveToPose_GetResult_Response__Sequence__init(jaime_interfaces__action__MoveToPose_GetResult_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  jaime_interfaces__action__MoveToPose_GetResult_Response * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(jaime_interfaces__action__MoveToPose_GetResult_Response)) {
      return false;
    }
    data = (jaime_interfaces__action__MoveToPose_GetResult_Response *)allocator.zero_allocate(size, sizeof(jaime_interfaces__action__MoveToPose_GetResult_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = jaime_interfaces__action__MoveToPose_GetResult_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        jaime_interfaces__action__MoveToPose_GetResult_Response__fini(&data[i - 1]);
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
jaime_interfaces__action__MoveToPose_GetResult_Response__Sequence__fini(jaime_interfaces__action__MoveToPose_GetResult_Response__Sequence * array)
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
      jaime_interfaces__action__MoveToPose_GetResult_Response__fini(&array->data[i]);
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

jaime_interfaces__action__MoveToPose_GetResult_Response__Sequence *
jaime_interfaces__action__MoveToPose_GetResult_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  jaime_interfaces__action__MoveToPose_GetResult_Response__Sequence * array = (jaime_interfaces__action__MoveToPose_GetResult_Response__Sequence *)allocator.allocate(sizeof(jaime_interfaces__action__MoveToPose_GetResult_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = jaime_interfaces__action__MoveToPose_GetResult_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
jaime_interfaces__action__MoveToPose_GetResult_Response__Sequence__destroy(jaime_interfaces__action__MoveToPose_GetResult_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    jaime_interfaces__action__MoveToPose_GetResult_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
jaime_interfaces__action__MoveToPose_GetResult_Response__Sequence__are_equal(const jaime_interfaces__action__MoveToPose_GetResult_Response__Sequence * lhs, const jaime_interfaces__action__MoveToPose_GetResult_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!jaime_interfaces__action__MoveToPose_GetResult_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
jaime_interfaces__action__MoveToPose_GetResult_Response__Sequence__copy(
  const jaime_interfaces__action__MoveToPose_GetResult_Response__Sequence * input,
  jaime_interfaces__action__MoveToPose_GetResult_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(jaime_interfaces__action__MoveToPose_GetResult_Response)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(jaime_interfaces__action__MoveToPose_GetResult_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    jaime_interfaces__action__MoveToPose_GetResult_Response * data =
      (jaime_interfaces__action__MoveToPose_GetResult_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!jaime_interfaces__action__MoveToPose_GetResult_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          jaime_interfaces__action__MoveToPose_GetResult_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!jaime_interfaces__action__MoveToPose_GetResult_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `info`
// already included above
// #include "service_msgs/msg/detail/service_event_info__functions.h"
// Member `request`
// Member `response`
// already included above
// #include "jaime_interfaces/action/detail/move_to_pose__functions.h"

bool
jaime_interfaces__action__MoveToPose_GetResult_Event__init(jaime_interfaces__action__MoveToPose_GetResult_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    jaime_interfaces__action__MoveToPose_GetResult_Event__fini(msg);
    return false;
  }
  // request
  if (!jaime_interfaces__action__MoveToPose_GetResult_Request__Sequence__init(&msg->request, 0)) {
    jaime_interfaces__action__MoveToPose_GetResult_Event__fini(msg);
    return false;
  }
  // response
  if (!jaime_interfaces__action__MoveToPose_GetResult_Response__Sequence__init(&msg->response, 0)) {
    jaime_interfaces__action__MoveToPose_GetResult_Event__fini(msg);
    return false;
  }
  return true;
}

void
jaime_interfaces__action__MoveToPose_GetResult_Event__fini(jaime_interfaces__action__MoveToPose_GetResult_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  jaime_interfaces__action__MoveToPose_GetResult_Request__Sequence__fini(&msg->request);
  // response
  jaime_interfaces__action__MoveToPose_GetResult_Response__Sequence__fini(&msg->response);
}

bool
jaime_interfaces__action__MoveToPose_GetResult_Event__are_equal(const jaime_interfaces__action__MoveToPose_GetResult_Event * lhs, const jaime_interfaces__action__MoveToPose_GetResult_Event * rhs)
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
  if (!jaime_interfaces__action__MoveToPose_GetResult_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!jaime_interfaces__action__MoveToPose_GetResult_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
jaime_interfaces__action__MoveToPose_GetResult_Event__copy(
  const jaime_interfaces__action__MoveToPose_GetResult_Event * input,
  jaime_interfaces__action__MoveToPose_GetResult_Event * output)
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
  if (!jaime_interfaces__action__MoveToPose_GetResult_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!jaime_interfaces__action__MoveToPose_GetResult_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

jaime_interfaces__action__MoveToPose_GetResult_Event *
jaime_interfaces__action__MoveToPose_GetResult_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  jaime_interfaces__action__MoveToPose_GetResult_Event * msg = (jaime_interfaces__action__MoveToPose_GetResult_Event *)allocator.allocate(sizeof(jaime_interfaces__action__MoveToPose_GetResult_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(jaime_interfaces__action__MoveToPose_GetResult_Event));
  bool success = jaime_interfaces__action__MoveToPose_GetResult_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
jaime_interfaces__action__MoveToPose_GetResult_Event__destroy(jaime_interfaces__action__MoveToPose_GetResult_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    jaime_interfaces__action__MoveToPose_GetResult_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
jaime_interfaces__action__MoveToPose_GetResult_Event__Sequence__init(jaime_interfaces__action__MoveToPose_GetResult_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  jaime_interfaces__action__MoveToPose_GetResult_Event * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(jaime_interfaces__action__MoveToPose_GetResult_Event)) {
      return false;
    }
    data = (jaime_interfaces__action__MoveToPose_GetResult_Event *)allocator.zero_allocate(size, sizeof(jaime_interfaces__action__MoveToPose_GetResult_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = jaime_interfaces__action__MoveToPose_GetResult_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        jaime_interfaces__action__MoveToPose_GetResult_Event__fini(&data[i - 1]);
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
jaime_interfaces__action__MoveToPose_GetResult_Event__Sequence__fini(jaime_interfaces__action__MoveToPose_GetResult_Event__Sequence * array)
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
      jaime_interfaces__action__MoveToPose_GetResult_Event__fini(&array->data[i]);
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

jaime_interfaces__action__MoveToPose_GetResult_Event__Sequence *
jaime_interfaces__action__MoveToPose_GetResult_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  jaime_interfaces__action__MoveToPose_GetResult_Event__Sequence * array = (jaime_interfaces__action__MoveToPose_GetResult_Event__Sequence *)allocator.allocate(sizeof(jaime_interfaces__action__MoveToPose_GetResult_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = jaime_interfaces__action__MoveToPose_GetResult_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
jaime_interfaces__action__MoveToPose_GetResult_Event__Sequence__destroy(jaime_interfaces__action__MoveToPose_GetResult_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    jaime_interfaces__action__MoveToPose_GetResult_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
jaime_interfaces__action__MoveToPose_GetResult_Event__Sequence__are_equal(const jaime_interfaces__action__MoveToPose_GetResult_Event__Sequence * lhs, const jaime_interfaces__action__MoveToPose_GetResult_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!jaime_interfaces__action__MoveToPose_GetResult_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
jaime_interfaces__action__MoveToPose_GetResult_Event__Sequence__copy(
  const jaime_interfaces__action__MoveToPose_GetResult_Event__Sequence * input,
  jaime_interfaces__action__MoveToPose_GetResult_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(jaime_interfaces__action__MoveToPose_GetResult_Event)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(jaime_interfaces__action__MoveToPose_GetResult_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    jaime_interfaces__action__MoveToPose_GetResult_Event * data =
      (jaime_interfaces__action__MoveToPose_GetResult_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!jaime_interfaces__action__MoveToPose_GetResult_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          jaime_interfaces__action__MoveToPose_GetResult_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!jaime_interfaces__action__MoveToPose_GetResult_Event__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `feedback`
// already included above
// #include "jaime_interfaces/action/detail/move_to_pose__functions.h"

bool
jaime_interfaces__action__MoveToPose_FeedbackMessage__init(jaime_interfaces__action__MoveToPose_FeedbackMessage * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    jaime_interfaces__action__MoveToPose_FeedbackMessage__fini(msg);
    return false;
  }
  // feedback
  if (!jaime_interfaces__action__MoveToPose_Feedback__init(&msg->feedback)) {
    jaime_interfaces__action__MoveToPose_FeedbackMessage__fini(msg);
    return false;
  }
  return true;
}

void
jaime_interfaces__action__MoveToPose_FeedbackMessage__fini(jaime_interfaces__action__MoveToPose_FeedbackMessage * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // feedback
  jaime_interfaces__action__MoveToPose_Feedback__fini(&msg->feedback);
}

bool
jaime_interfaces__action__MoveToPose_FeedbackMessage__are_equal(const jaime_interfaces__action__MoveToPose_FeedbackMessage * lhs, const jaime_interfaces__action__MoveToPose_FeedbackMessage * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // feedback
  if (!jaime_interfaces__action__MoveToPose_Feedback__are_equal(
      &(lhs->feedback), &(rhs->feedback)))
  {
    return false;
  }
  return true;
}

bool
jaime_interfaces__action__MoveToPose_FeedbackMessage__copy(
  const jaime_interfaces__action__MoveToPose_FeedbackMessage * input,
  jaime_interfaces__action__MoveToPose_FeedbackMessage * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // feedback
  if (!jaime_interfaces__action__MoveToPose_Feedback__copy(
      &(input->feedback), &(output->feedback)))
  {
    return false;
  }
  return true;
}

jaime_interfaces__action__MoveToPose_FeedbackMessage *
jaime_interfaces__action__MoveToPose_FeedbackMessage__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  jaime_interfaces__action__MoveToPose_FeedbackMessage * msg = (jaime_interfaces__action__MoveToPose_FeedbackMessage *)allocator.allocate(sizeof(jaime_interfaces__action__MoveToPose_FeedbackMessage), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(jaime_interfaces__action__MoveToPose_FeedbackMessage));
  bool success = jaime_interfaces__action__MoveToPose_FeedbackMessage__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
jaime_interfaces__action__MoveToPose_FeedbackMessage__destroy(jaime_interfaces__action__MoveToPose_FeedbackMessage * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    jaime_interfaces__action__MoveToPose_FeedbackMessage__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
jaime_interfaces__action__MoveToPose_FeedbackMessage__Sequence__init(jaime_interfaces__action__MoveToPose_FeedbackMessage__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  jaime_interfaces__action__MoveToPose_FeedbackMessage * data = NULL;

  if (size) {
    if (size > SIZE_MAX / sizeof(jaime_interfaces__action__MoveToPose_FeedbackMessage)) {
      return false;
    }
    data = (jaime_interfaces__action__MoveToPose_FeedbackMessage *)allocator.zero_allocate(size, sizeof(jaime_interfaces__action__MoveToPose_FeedbackMessage), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = jaime_interfaces__action__MoveToPose_FeedbackMessage__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        jaime_interfaces__action__MoveToPose_FeedbackMessage__fini(&data[i - 1]);
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
jaime_interfaces__action__MoveToPose_FeedbackMessage__Sequence__fini(jaime_interfaces__action__MoveToPose_FeedbackMessage__Sequence * array)
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
      jaime_interfaces__action__MoveToPose_FeedbackMessage__fini(&array->data[i]);
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

jaime_interfaces__action__MoveToPose_FeedbackMessage__Sequence *
jaime_interfaces__action__MoveToPose_FeedbackMessage__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  jaime_interfaces__action__MoveToPose_FeedbackMessage__Sequence * array = (jaime_interfaces__action__MoveToPose_FeedbackMessage__Sequence *)allocator.allocate(sizeof(jaime_interfaces__action__MoveToPose_FeedbackMessage__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = jaime_interfaces__action__MoveToPose_FeedbackMessage__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
jaime_interfaces__action__MoveToPose_FeedbackMessage__Sequence__destroy(jaime_interfaces__action__MoveToPose_FeedbackMessage__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    jaime_interfaces__action__MoveToPose_FeedbackMessage__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
jaime_interfaces__action__MoveToPose_FeedbackMessage__Sequence__are_equal(const jaime_interfaces__action__MoveToPose_FeedbackMessage__Sequence * lhs, const jaime_interfaces__action__MoveToPose_FeedbackMessage__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!jaime_interfaces__action__MoveToPose_FeedbackMessage__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
jaime_interfaces__action__MoveToPose_FeedbackMessage__Sequence__copy(
  const jaime_interfaces__action__MoveToPose_FeedbackMessage__Sequence * input,
  jaime_interfaces__action__MoveToPose_FeedbackMessage__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    if (input->size > SIZE_MAX / sizeof(jaime_interfaces__action__MoveToPose_FeedbackMessage)) {
      return false;
    }
    const size_t allocation_size =
      input->size * sizeof(jaime_interfaces__action__MoveToPose_FeedbackMessage);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    jaime_interfaces__action__MoveToPose_FeedbackMessage * data =
      (jaime_interfaces__action__MoveToPose_FeedbackMessage *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!jaime_interfaces__action__MoveToPose_FeedbackMessage__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          jaime_interfaces__action__MoveToPose_FeedbackMessage__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!jaime_interfaces__action__MoveToPose_FeedbackMessage__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
