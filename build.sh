#!/bin/sh
set -x
cd ./file_copy
make
mkdir ../bin
cp ./app ../bin/app
rm -f ./app
rm -f ./main.o
