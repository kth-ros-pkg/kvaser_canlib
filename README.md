kvaser_canlib
=============

Overview
---------------------------------------------

Installs drivers and header files for Kvaser CAN cards. Requires sudo rights for installation of libraries and header files.


Installing
---------------------------------------------

Create an empty catkin workspace:

    mkdir -p ~/canlib_ws/src
    cd ~/canlib_ws/src/
    catkin_init_workspace

**NB: Make sure that the catkin workspace you create does not contain any other packages depending on Kvaser's canlib. This package installs the libraries as an external project and does not generate/export the library itself.**

If you try to compile this package at the same time as other packages that depend on canlib, CMake will give you errors!

Clone the git repository in the workspace:
    
    cd ~/canlib_ws/src
    git clone https://github.com/kth-ros-pkg/kvaser_canlib.git -v groovy

Compile:
 
    cd ~/canlib_ws
    catkin_make    

You will be prompted for a **sudo password** for installation.

The library will be downloaded and built under `~/canlib_ws/build/kvaser_canlib/src/canlib_`. 


Compiling packages which use Kvaser CAN cards
---------------------------------------------

Source files should include the canlib.h header file:
 
    #include <kvaser_canlib/canlib.h>


Remember to add the `canlib` library for linking in dependent packages, e.g.:

     add_executable(test src/test.cpp)
     target_link_libraries(test canlib ${catkin_LIBRARIES})


Other ways of installing Kvaser CAN lib
---------------------------------------------

Visit the kvaser download page `http://www.kvaser.com/en/support/downloads.html` and download the `Kvaser LINUX Driver and SDK`.
