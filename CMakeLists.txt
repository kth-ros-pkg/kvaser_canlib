cmake_minimum_required(VERSION 2.8.3)

include(ExternalProject)
ExternalProject_Add(canlib_
  PREFIX ${CMAKE_CURRENT_BINARY_DIR}
  DOWNLOAD_DIR ${CMAKE_CURRENT_BINARY_DIR}/download
  URL http://www.csc.kth.se/~fevb/downloads/linuxcan.tar.gz
  URL_MD5 c4051f7935cac72441a4f8107a3cbe1a
  CONFIGURE_COMMAND "" # there is no configuration file
  BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR}/src/canlib_
  BUILD_COMMAND make
  INSTALL_COMMAND sudo make install 
)

project(kvaser_canlib)

find_package(catkin REQUIRED)

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES
)

install(DIRECTORY include/${PROJECT_NAME}/
   DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
   FILES_MATCHING PATTERN "*.h"
)

# install(FILES
#    ${CATKIN_DEVEL_PREFIX}/lib/libcanlib.so
#    ${CATKIN_DEVEL_PREFIX}/lib/libcanlib.so.1
#    ${CATKIN_DEVEL_PREFIX}/lib/libcanlib.so.1.1.0
#    DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
# )
