// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from jaime_interfaces:srv/IsReady.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "jaime_interfaces/srv/is_ready.h"


#ifndef JAIME_INTERFACES__SRV__DETAIL__IS_READY__FUNCTIONS_H_
#define JAIME_INTERFACES__SRV__DETAIL__IS_READY__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/action_type_support_struct.h"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_runtime_c/service_type_support_struct.h"
#include "rosidl_runtime_c/type_description/type_description__struct.h"
#include "rosidl_runtime_c/type_description/type_source__struct.h"
#include "rosidl_runtime_c/type_hash.h"
#include "rosidl_runtime_c/visibility_control.h"
#include "jaime_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "jaime_interfaces/srv/detail/is_ready__struct.h"

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_jaime_interfaces
const rosidl_type_hash_t *
jaime_interfaces__srv__IsReady__get_type_hash(
  const rosidl_service_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_jaime_interfaces
const rosidl_runtime_c__type_description__TypeDescription *
jaime_interfaces__srv__IsReady__get_type_description(
  const rosidl_service_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_jaime_interfaces
const rosidl_runtime_c__type_description__TypeSource *
jaime_interfaces__srv__IsReady__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_jaime_interfaces
const rosidl_runtime_c__type_description__TypeSource__Sequence *
jaime_interfaces__srv__IsReady__get_type_description_sources(
  const rosidl_service_type_support_t * type_support);

/// Initialize srv/IsReady message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * jaime_interfaces__srv__IsReady_Request
 * )) before or use
 * jaime_interfaces__srv__IsReady_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_jaime_interfaces
bool
jaime_interfaces__srv__IsReady_Request__init(jaime_interfaces__srv__IsReady_Request * msg);

/// Finalize srv/IsReady message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_jaime_interfaces
void
jaime_interfaces__srv__IsReady_Request__fini(jaime_interfaces__srv__IsReady_Request * msg);

/// Create srv/IsReady message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * jaime_interfaces__srv__IsReady_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_jaime_interfaces
jaime_interfaces__srv__IsReady_Request *
jaime_interfaces__srv__IsReady_Request__create(void);

/// Destroy srv/IsReady message.
/**
 * It calls
 * jaime_interfaces__srv__IsReady_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_jaime_interfaces
void
jaime_interfaces__srv__IsReady_Request__destroy(jaime_interfaces__srv__IsReady_Request * msg);

/// Check for srv/IsReady message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_jaime_interfaces
bool
jaime_interfaces__srv__IsReady_Request__are_equal(const jaime_interfaces__srv__IsReady_Request * lhs, const jaime_interfaces__srv__IsReady_Request * rhs);

/// Copy a srv/IsReady message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_jaime_interfaces
bool
jaime_interfaces__srv__IsReady_Request__copy(
  const jaime_interfaces__srv__IsReady_Request * input,
  jaime_interfaces__srv__IsReady_Request * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_jaime_interfaces
const rosidl_type_hash_t *
jaime_interfaces__srv__IsReady_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_jaime_interfaces
const rosidl_runtime_c__type_description__TypeDescription *
jaime_interfaces__srv__IsReady_Request__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_jaime_interfaces
const rosidl_runtime_c__type_description__TypeSource *
jaime_interfaces__srv__IsReady_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_jaime_interfaces
const rosidl_runtime_c__type_description__TypeSource__Sequence *
jaime_interfaces__srv__IsReady_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of srv/IsReady messages.
/**
 * It allocates the memory for the number of elements and calls
 * jaime_interfaces__srv__IsReady_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_jaime_interfaces
bool
jaime_interfaces__srv__IsReady_Request__Sequence__init(jaime_interfaces__srv__IsReady_Request__Sequence * array, size_t size);

/// Finalize array of srv/IsReady messages.
/**
 * It calls
 * jaime_interfaces__srv__IsReady_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_jaime_interfaces
void
jaime_interfaces__srv__IsReady_Request__Sequence__fini(jaime_interfaces__srv__IsReady_Request__Sequence * array);

/// Create array of srv/IsReady messages.
/**
 * It allocates the memory for the array and calls
 * jaime_interfaces__srv__IsReady_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_jaime_interfaces
jaime_interfaces__srv__IsReady_Request__Sequence *
jaime_interfaces__srv__IsReady_Request__Sequence__create(size_t size);

/// Destroy array of srv/IsReady messages.
/**
 * It calls
 * jaime_interfaces__srv__IsReady_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_jaime_interfaces
void
jaime_interfaces__srv__IsReady_Request__Sequence__destroy(jaime_interfaces__srv__IsReady_Request__Sequence * array);

/// Check for srv/IsReady message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_jaime_interfaces
bool
jaime_interfaces__srv__IsReady_Request__Sequence__are_equal(const jaime_interfaces__srv__IsReady_Request__Sequence * lhs, const jaime_interfaces__srv__IsReady_Request__Sequence * rhs);

/// Copy an array of srv/IsReady messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_jaime_interfaces
bool
jaime_interfaces__srv__IsReady_Request__Sequence__copy(
  const jaime_interfaces__srv__IsReady_Request__Sequence * input,
  jaime_interfaces__srv__IsReady_Request__Sequence * output);

/// Initialize srv/IsReady message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * jaime_interfaces__srv__IsReady_Response
 * )) before or use
 * jaime_interfaces__srv__IsReady_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_jaime_interfaces
bool
jaime_interfaces__srv__IsReady_Response__init(jaime_interfaces__srv__IsReady_Response * msg);

/// Finalize srv/IsReady message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_jaime_interfaces
void
jaime_interfaces__srv__IsReady_Response__fini(jaime_interfaces__srv__IsReady_Response * msg);

/// Create srv/IsReady message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * jaime_interfaces__srv__IsReady_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_jaime_interfaces
jaime_interfaces__srv__IsReady_Response *
jaime_interfaces__srv__IsReady_Response__create(void);

/// Destroy srv/IsReady message.
/**
 * It calls
 * jaime_interfaces__srv__IsReady_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_jaime_interfaces
void
jaime_interfaces__srv__IsReady_Response__destroy(jaime_interfaces__srv__IsReady_Response * msg);

/// Check for srv/IsReady message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_jaime_interfaces
bool
jaime_interfaces__srv__IsReady_Response__are_equal(const jaime_interfaces__srv__IsReady_Response * lhs, const jaime_interfaces__srv__IsReady_Response * rhs);

/// Copy a srv/IsReady message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_jaime_interfaces
bool
jaime_interfaces__srv__IsReady_Response__copy(
  const jaime_interfaces__srv__IsReady_Response * input,
  jaime_interfaces__srv__IsReady_Response * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_jaime_interfaces
const rosidl_type_hash_t *
jaime_interfaces__srv__IsReady_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_jaime_interfaces
const rosidl_runtime_c__type_description__TypeDescription *
jaime_interfaces__srv__IsReady_Response__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_jaime_interfaces
const rosidl_runtime_c__type_description__TypeSource *
jaime_interfaces__srv__IsReady_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_jaime_interfaces
const rosidl_runtime_c__type_description__TypeSource__Sequence *
jaime_interfaces__srv__IsReady_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of srv/IsReady messages.
/**
 * It allocates the memory for the number of elements and calls
 * jaime_interfaces__srv__IsReady_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_jaime_interfaces
bool
jaime_interfaces__srv__IsReady_Response__Sequence__init(jaime_interfaces__srv__IsReady_Response__Sequence * array, size_t size);

/// Finalize array of srv/IsReady messages.
/**
 * It calls
 * jaime_interfaces__srv__IsReady_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_jaime_interfaces
void
jaime_interfaces__srv__IsReady_Response__Sequence__fini(jaime_interfaces__srv__IsReady_Response__Sequence * array);

/// Create array of srv/IsReady messages.
/**
 * It allocates the memory for the array and calls
 * jaime_interfaces__srv__IsReady_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_jaime_interfaces
jaime_interfaces__srv__IsReady_Response__Sequence *
jaime_interfaces__srv__IsReady_Response__Sequence__create(size_t size);

/// Destroy array of srv/IsReady messages.
/**
 * It calls
 * jaime_interfaces__srv__IsReady_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_jaime_interfaces
void
jaime_interfaces__srv__IsReady_Response__Sequence__destroy(jaime_interfaces__srv__IsReady_Response__Sequence * array);

/// Check for srv/IsReady message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_jaime_interfaces
bool
jaime_interfaces__srv__IsReady_Response__Sequence__are_equal(const jaime_interfaces__srv__IsReady_Response__Sequence * lhs, const jaime_interfaces__srv__IsReady_Response__Sequence * rhs);

/// Copy an array of srv/IsReady messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_jaime_interfaces
bool
jaime_interfaces__srv__IsReady_Response__Sequence__copy(
  const jaime_interfaces__srv__IsReady_Response__Sequence * input,
  jaime_interfaces__srv__IsReady_Response__Sequence * output);

/// Initialize srv/IsReady message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * jaime_interfaces__srv__IsReady_Event
 * )) before or use
 * jaime_interfaces__srv__IsReady_Event__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_jaime_interfaces
bool
jaime_interfaces__srv__IsReady_Event__init(jaime_interfaces__srv__IsReady_Event * msg);

/// Finalize srv/IsReady message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_jaime_interfaces
void
jaime_interfaces__srv__IsReady_Event__fini(jaime_interfaces__srv__IsReady_Event * msg);

/// Create srv/IsReady message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * jaime_interfaces__srv__IsReady_Event__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_jaime_interfaces
jaime_interfaces__srv__IsReady_Event *
jaime_interfaces__srv__IsReady_Event__create(void);

/// Destroy srv/IsReady message.
/**
 * It calls
 * jaime_interfaces__srv__IsReady_Event__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_jaime_interfaces
void
jaime_interfaces__srv__IsReady_Event__destroy(jaime_interfaces__srv__IsReady_Event * msg);

/// Check for srv/IsReady message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_jaime_interfaces
bool
jaime_interfaces__srv__IsReady_Event__are_equal(const jaime_interfaces__srv__IsReady_Event * lhs, const jaime_interfaces__srv__IsReady_Event * rhs);

/// Copy a srv/IsReady message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_jaime_interfaces
bool
jaime_interfaces__srv__IsReady_Event__copy(
  const jaime_interfaces__srv__IsReady_Event * input,
  jaime_interfaces__srv__IsReady_Event * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_jaime_interfaces
const rosidl_type_hash_t *
jaime_interfaces__srv__IsReady_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_jaime_interfaces
const rosidl_runtime_c__type_description__TypeDescription *
jaime_interfaces__srv__IsReady_Event__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_jaime_interfaces
const rosidl_runtime_c__type_description__TypeSource *
jaime_interfaces__srv__IsReady_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_jaime_interfaces
const rosidl_runtime_c__type_description__TypeSource__Sequence *
jaime_interfaces__srv__IsReady_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of srv/IsReady messages.
/**
 * It allocates the memory for the number of elements and calls
 * jaime_interfaces__srv__IsReady_Event__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_jaime_interfaces
bool
jaime_interfaces__srv__IsReady_Event__Sequence__init(jaime_interfaces__srv__IsReady_Event__Sequence * array, size_t size);

/// Finalize array of srv/IsReady messages.
/**
 * It calls
 * jaime_interfaces__srv__IsReady_Event__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_jaime_interfaces
void
jaime_interfaces__srv__IsReady_Event__Sequence__fini(jaime_interfaces__srv__IsReady_Event__Sequence * array);

/// Create array of srv/IsReady messages.
/**
 * It allocates the memory for the array and calls
 * jaime_interfaces__srv__IsReady_Event__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_jaime_interfaces
jaime_interfaces__srv__IsReady_Event__Sequence *
jaime_interfaces__srv__IsReady_Event__Sequence__create(size_t size);

/// Destroy array of srv/IsReady messages.
/**
 * It calls
 * jaime_interfaces__srv__IsReady_Event__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_jaime_interfaces
void
jaime_interfaces__srv__IsReady_Event__Sequence__destroy(jaime_interfaces__srv__IsReady_Event__Sequence * array);

/// Check for srv/IsReady message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_jaime_interfaces
bool
jaime_interfaces__srv__IsReady_Event__Sequence__are_equal(const jaime_interfaces__srv__IsReady_Event__Sequence * lhs, const jaime_interfaces__srv__IsReady_Event__Sequence * rhs);

/// Copy an array of srv/IsReady messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_jaime_interfaces
bool
jaime_interfaces__srv__IsReady_Event__Sequence__copy(
  const jaime_interfaces__srv__IsReady_Event__Sequence * input,
  jaime_interfaces__srv__IsReady_Event__Sequence * output);
#ifdef __cplusplus
}
#endif

#endif  // JAIME_INTERFACES__SRV__DETAIL__IS_READY__FUNCTIONS_H_
