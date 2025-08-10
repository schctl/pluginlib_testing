cmake_minimum_required(VERSION 3.8)
project(pkg_a)

find_package(ament_cmake REQUIRED)

## ----- Test Exe ---------------------------------------

add_executable(test_plugin src/test_plugin.cpp)

target_include_directories(test_plugin PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

find_package(pluginlib REQUIRED)

ament_target_dependencies(test_plugin PUBLIC pluginlib)

install(TARGETS test_plugin
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION lib/${PROJECT_NAME}
)

## ----- Install pkg_a -----------------------------------------

install(
  DIRECTORY include/
  DESTINATION include/
)

## ----- Ament ---------------------------------------

ament_export_include_directories(
  include/
)
ament_package()
