cmake_minimum_required(VERSION 3.8)
project(jaime_manipulation)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# ------------------------------------------------------------------------------
# Dependencies
# ------------------------------------------------------------------------------

find_package(ament_cmake REQUIRED)
find_package(jaime_interfaces REQUIRED)

# ------------------------------------------------------------------------------
# Testing
# ------------------------------------------------------------------------------

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)

  # the following line skips the linter which checks for copyrights
  set(ament_cmake_copyright_FOUND TRUE)

  # the following line skips cpplint
  set(ament_cmake_cpplint_FOUND TRUE)

  ament_lint_auto_find_test_dependencies()
endif()

# ------------------------------------------------------------------------------
# Install
# ------------------------------------------------------------------------------

install(
  DIRECTORY
    launch
    scripts
    config
  DESTINATION
    share/${PROJECT_NAME}
)

install(
  PROGRAMS
    scripts/dynamixel_publish.py
    scripts/joint_pose_action_server.py
    scripts/local_planner.py
    scripts/read_encoders.py
    scripts/sim_node.py
    scripts/face_detector.py
    scripts/face_follower.py
    scripts/utils.py
    scripts/fk_solution.py
    scripts/__init__.py
  DESTINATION
    lib/${PROJECT_NAME}
)

ament_package()
