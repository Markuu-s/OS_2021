cd ../ex1/
sudo chmod 777 lofsdisk
cd ../ex1/lofsdisk/
sudo chmod 777 *
sudo echo "Mark" > file1.txt
sudo echo "Esaian" > file2.txt
sudo chmod 777 *
cd ../../ex2
sudo gcc ex2.c -o ex2.out
sudo ./ex2.out
cd ../ex1/lofsdisk/
sudo cp ../../ex2/ex2.out .

cd ../
sudo mkdir lofsdisk/lib
sudo mkdir lofsdisk/lib/x86_64-linux-gnu
sudo cp /lib/x86_64-linux-gnu/libtinfo.so.6 lofsdisk/lib/x86_64-linux-gnu
sudo cp /lib/x86_64-linux-gnu/libdl.so.2 lofsdisk/lib/x86_64-linux-gnu
sudo cp /lib/x86_64-linux-gnu/libc.so.6 lofsdisk/lib/x86_64-linux-gnu
sudo mkdir lofsdisk/lib64
sudo cp /lib64/ld-linux-x86-64.so.2 lofsdisk/lib64/
sudo cp /lib/x86_64-linux-gnu/libselinux.so.1 lofsdisk/lib/x86_64-linux-gnu
sudo cp /lib/x86_64-linux-gnu/libpcre2-8.so.0 lofsdisk/lib/x86_64-linux-gnu
sudo cp /lib/x86_64-linux-gnu/libpthread.so.0 lofsdisk/lib/x86_64-linux-gnu
sudo cp /bin/bash lofsdisk/bin/
sudo cp /bin/cat lofsdisk/bin/
sudo cp /bin/ls lofsdisk/bin/
cd lofsdisk/

sudo ./ex2.out > ../../ex2/ex2.txt
