#!/bin/bash
echo "building code!"
echo
echo
rm -rf ./bin
mkdir -p ./bin
cd ./bin
#we have tp go in a compile our code 
cc -Wall -std=c11 -c ../src/*.c
#we have to link our .o to the executable
cc -o c_adv *.o
#we have to execute our project
./c_adv #run our executable
echo
echo
