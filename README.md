kvaser_canlib
=============

Installs drivers and header files for Kvaser CAN cards. Requires sudo rights for installation of libraries and header files.

Remember to add the canlib library for linking in dependent packages, e.g.:

add_executable(test.cpp src/test.cpp)

target_link_libraries(myexec canlib ${catkin_LIBRARIES})
