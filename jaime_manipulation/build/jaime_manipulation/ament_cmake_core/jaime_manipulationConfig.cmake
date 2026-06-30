# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_jaime_manipulation_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED jaime_manipulation_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(jaime_manipulation_FOUND FALSE)
  elseif(NOT jaime_manipulation_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(jaime_manipulation_FOUND FALSE)
  endif()
  return()
endif()
set(_jaime_manipulation_CONFIG_INCLUDED TRUE)

# output package information
if(NOT jaime_manipulation_FIND_QUIETLY)
  message(STATUS "Found jaime_manipulation: 0.0.0 (${jaime_manipulation_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'jaime_manipulation' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT jaime_manipulation_DEPRECATED_QUIET)
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(jaime_manipulation_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${jaime_manipulation_DIR}/${_extra}")
endforeach()
