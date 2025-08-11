cmake_minimum_required(VERSION 3.8)
project(pkg_b)

find_package(ament_cmake REQUIRED)

add_library(pkg_b SHARED src/plugin_impl.cpp)
target_include_directories(pkg_b PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

## ----- Dependencies -----------------------------------------

set(THIS_PACKAGE_INCLUDE_DEPENDS)

foreach(Dependency IN ITEMS ${THIS_PACKAGE_INCLUDE_DEPENDS})
  find_package(${Dependency} REQUIRED)
endforeach()

## ----- Install -----------------------------------------

install(
  DIRECTORY include/
  DESTINATION include/
)
install(TARGETS pkg_b
  EXPORT export_pkg_b
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
)

## ----- Build Setup -----------------------------------------

find_package(pkg_a QUIET)

if (pkg_a_FOUND)
  message(WARNING "Found pkg_a")

  find_package(pluginlib REQUIRED)

  list(APPEND THIS_PACKAGE_INCLUDE_DEPENDS
    pkg_a
    pluginlib
  )

else()
  message(WARNING "pkg_a not found, skipping pkg_a")
endif()

ament_target_dependencies(
  pkg_b PUBLIC
  ${THIS_PACKAGE_INCLUDE_DEPENDS}
)

if (pkg_a_FOUND)
  pluginlib_export_plugin_description_file(pkg_a plugins.xml)
endif()

ament_export_targets(export_pkg_b HAS_LIBRARY_TARGET)
ament_export_dependencies(${THIS_PACKAGE_INCLUDE_DEPENDS})
ament_package()
