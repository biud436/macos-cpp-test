#!/bin/sh
set -x
if [! -d "./bin" ]; then
	echo "create a new folder called 'bin'"
	mkdir ./bin
fi
cd ./file_copy
make
mkdir ../bin
cp ./app ../bin/app
rm -f ./app
rm -f ./main.o
