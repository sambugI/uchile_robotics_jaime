cmake_minimum_required(VERSION 3.8)
project(jaime_bringup)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()


find_package(ament_cmake REQUIRED)


# Dependencias usadas por localization_manager.py
find_package(jaime_interfaces REQUIRED)
find_package(rclpy REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(nav_msgs REQUIRED)


# Archivos launch
install(
  DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}/
)


# Mapas
install(
  DIRECTORY maps/
  DESTINATION share/${PROJECT_NAME}/maps/
)


# Parámetros
install(
  DIRECTORY params/
  DESTINATION share/${PROJECT_NAME}/params/
)


# Scripts Python
install(
  PROGRAMS
    scripts/localization_manager.py
  DESTINATION lib/${PROJECT_NAME}
)

install(
  PROGRAMS
    scripts/basic_manager.py
    scripts/localization_manager.py
    scripts/navigation_manager.py
    scripts/tablet_manager.py
    scripts/percepcion_manager.py
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
