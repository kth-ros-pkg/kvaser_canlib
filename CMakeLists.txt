cmake_minimum_required(VERSION 2.8.3)
project(kvaser_canlib)

include(ExternalProject)
ExternalProject_Add(canlib_
  PREFIX ${CMAKE_CURRENT_BINARY_DIR}
  DOWNLOAD_DIR ${CMAKE_CURRENT_BINARY_DIR}/download
  URL http://www.kvaser.com/software/7330130980754/V5_3_0/linuxcan.tar.gz
  URL_MD5 7d6d97266fd370d4233cbc1e0a917e82
  CONFIGURE_COMMAND "" # there is no configuration file
  BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR}/src/canlib_
  BUILD_COMMAND make
  INSTALL_COMMAND sudo make install 
)

add_custom_target(
  copy_canlib ALL
  COMMAND cmake -E copy ${CMAKE_CURRENT_BINARY_DIR}/src/canlib_/canlib/libcanlib.so ${CATKIN_DEVEL_PREFIX}/${CATKIN_GLOBAL_LIB_DESTINATION}/libcanlib.so)

add_custom_target(
  copy_canlib1 ALL
  COMMAND cmake -E copy ${CMAKE_CURRENT_BINARY_DIR}/src/canlib_/canlib/libcanlib.so.1 ${CATKIN_DEVEL_PREFIX}/${CATKIN_GLOBAL_LIB_DESTINATION}/libcanlib.so.1)

add_custom_target(
  copy_canlib110 ALL
  COMMAND cmake -E copy ${CMAKE_CURRENT_BINARY_DIR}/src/canlib_/canlib/libcanlib.so.1.1.0 ${CATKIN_DEVEL_PREFIX}/${CATKIN_GLOBAL_LIB_DESTINATION}/libcanlib.so.1.1.0)

add_library(canlib SHARED)
set_target_properties(canlib PROPERTIES LINKER_LANGUAGE CXX)

add_dependencies(canlib copy_canlib)
add_dependencies(canlib copy_canlib1)
add_dependencies(canlib copy_canlib110)
add_dependencies(copy_canlib canlib_)
add_dependencies(copy_canlib1 canlib_)
add_dependencies(copy_canlib110 canlib_)

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES canlib
)

install(DIRECTORY include/${PROJECT_NAME}/
   DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
   FILES_MATCHING PATTERN "*.h"
)

