sudo apt-get install build-essential
rospack profile
roscd kvaser_canlib
tar -xzf linuxcan.tar.gz
cd linuxcan/
sudo make install