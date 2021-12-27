#!/bin/sh

# adding force executing
set -x
cd ./file_copy

# compile program
make

# ignore standard output.
mkdir ../bin >/dev/null 2>&1

# copy file
cp ./app ../bin/app

# remove created file after compiling
rm -f ./app
rm -f ./main.o
