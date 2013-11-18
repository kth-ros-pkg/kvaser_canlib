kvaser_canlib
=============

Overview
---------------------------------------------

Installs drivers and header files for Kvaser CAN cards. Requires sudo rights for installation of libraries and header files.


Installing
---------------------------------------------

Create an empty catkin workspace:

    mkdir -p ~/catkin_ws/src
    cd ~/catkin_ws/src/
    catkin_init_workspace

Clone the git repository in the workspace:
    
    cd ~/catkin_ws/src
    git clone -b groovy https://github.com/kth-ros-pkg/kvaser_canlib.git

Source the setup.bash file and compile:
 
    source ~/catkin_ws/devel/setup.bash
    cd ~/catkin_ws
    catkin_make    

You will be prompted for a **sudo password** for installation.

The library will be downloaded and built under `~/catkin_ws/build/kvaser_canlib/src/canlib_`. 


Compiling packages which use Kvaser CAN cards
---------------------------------------------

Source files should include the canlib.h header file:
 
    #include <kvaser_canlib/canlib.h>



Other ways of installing Kvaser CAN lib
---------------------------------------------

Visit the kvaser download page `http://www.kvaser.com/en/support/downloads.html` and download the `Kvaser LINUX Driver and SDK`.
