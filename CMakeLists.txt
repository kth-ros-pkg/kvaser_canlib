cmake_minimum_required(VERSION 2.8.3)
project(kvaser_canlib)

find_package(catkin REQUIRED COMPONENTS)


link_directories(
 ${catkin_LIBRARY_DIRS}
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

catkin_package(
 INCLUDE_DIRS include
 # LIBRARIES canlib
#  CATKIN_DEPENDS 
#  DEPENDS system_lib
)

# TODO: very dirty.. have to clean this up

# add_custom_target(
#   build_kvaser_canlib ALL
#   COMMAND cmake -E chdir ${PROJECT_SOURCE_DIR} make -f Makefile.tarball && mkdir -p ${CATKIN_DEVEL_PREFIX}/${CATKIN_GLOBAL_LIB_DESTINATION}/${PROJECT_NAME})

# add_custom_target(
#     copy_kvaser_canlib ALL
#     COMMAND cmake -E copy ${PROJECT_SOURCE_DIR}/lib/libcanlib.so  ${CATKIN_DEVEL_PREFIX}/${CATKIN_GLOBAL_LIB_DESTINATION}/${PROJECT_NAME})

# add_custom_target(
#     copy_kvaser_canlib1 ALL
#     COMMAND cmake -E copy ${PROJECT_SOURCE_DIR}/lib/libcanlib.so.1  ${CATKIN_DEVEL_PREFIX}/${CATKIN_GLOBAL_LIB_DESTINATION}/${PROJECT_NAME})

# add_custom_target(
#     copy_kvaser_canlib110 ALL
#     COMMAND cmake -E copy ${PROJECT_SOURCE_DIR}/lib/libcanlib.so.1.1.0  ${CATKIN_DEVEL_PREFIX}/${CATKIN_GLOBAL_LIB_DESTINATION}/${PROJECT_NAME})

# ##########################

add_custom_target(
  build_kvaser_canlib ALL
  COMMAND cmake -E chdir ${PROJECT_SOURCE_DIR} make -f Makefile.tarball)

# add_custom_target(
#     copy_kvaser_canlib ALL
#     COMMAND cmake -E copy ${PROJECT_SOURCE_DIR}/lib/libcanlib.so  ${CATKIN_DEVEL_PREFIX}/${CATKIN_GLOBAL_LIB_DESTINATION}/)

# add_custom_target(
#     copy_kvaser_canlib1 ALL
#     COMMAND cmake -E copy ${PROJECT_SOURCE_DIR}/lib/libcanlib.so.1  ${CATKIN_DEVEL_PREFIX}/${CATKIN_GLOBAL_LIB_DESTINATION}/)

# add_custom_target(
#     copy_kvaser_canlib110 ALL
#     COMMAND cmake -E copy ${PROJECT_SOURCE_DIR}/lib/libcanlib.so.1.1.0  ${CATKIN_DEVEL_PREFIX}/${CATKIN_GLOBAL_LIB_DESTINATION}/)

# for removing the fake libcanlib.so
# add_custom_target(
#     rm_canlib ALL
#     COMMAND rm ${CATKIN_DEVEL_PREFIX}/${CATKIN_GLOBAL_LIB_DESTINATION}/libcanlib.so)

# add_custom_target(
#     rm_canlib ALL
#     COMMAND cp ${CATKIN_DEVEL_PREFIX}/${CATKIN_GLOBAL_LIB_DESTINATION}/${PROJECT_NAME}/libcanlib.so ${CATKIN_DEVEL_PREFIX}/${CATKIN_GLOBAL_LIB_DESTINATION}/libcanlib.so)

# TODO: clean this up... very nasty
# add_library(canlib SHARED)
# set_target_properties(canlib PROPERTIES LINKER_LANGUAGE CXX)


# # add_dependencies(rm_canlib canlib)

# add_dependencies(canlib copy_kvaser_canlib)
# add_dependencies(canlib copy_kvaser_canlib1)
# add_dependencies(canlib copy_kvaser_canlib110)
# add_dependencies(copy_kvaser_canlib build_kvaser_canlib)
# add_dependencies(copy_kvaser_canlib1 build_kvaser_canlib)
# add_dependencies(copy_kvaser_canlib110 build_kvaser_canlib)

