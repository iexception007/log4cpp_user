# log4cpp_user
how to use the log4cpp 
env: ubuntu 14.2

sudo tar -zxvf log4cpp-1.1.2rc1.tar.gz
sudo ./configrue
sudo make
sudo make install

sudo mkdir bin
sudo cp /usr/local/lib/log4cpp.so.5 /bin/log4cpp.so.5

sudo make
cd bin
./Testor

