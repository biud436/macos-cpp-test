#!/bin/sh
set -x
cd ./file_copy
make
mkdir ../bin >/dev/null 2>&1
cp ./app ../bin/app
rm -f ./app
rm -f ./main.o
