# generated from rosidl_cmake/cmake/rosidl_cmake_aggregate_target-extras.cmake.in

# Create a convenience aggregate target jaime_interfaces::jaime_interfaces
# that links all generated interface targets, so downstream packages can use
# a single modern CMake target name instead of ${jaime_interfaces_TARGETS}.
if(jaime_interfaces_TARGETS AND NOT TARGET jaime_interfaces::jaime_interfaces)
  add_library(jaime_interfaces::jaime_interfaces INTERFACE IMPORTED)
  set_target_properties(jaime_interfaces::jaime_interfaces PROPERTIES
    INTERFACE_LINK_LIBRARIES "${jaime_interfaces_TARGETS}")
endif()
