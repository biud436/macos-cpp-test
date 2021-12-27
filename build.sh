#!/bin/sh

# adding force executing
set -x
cd ./file_copy
make

# ignore standard output.
mkdir ../bin >/dev/null 2>&1
cp ./app ../bin/app
rm -f ./app
rm -f ./main.o
