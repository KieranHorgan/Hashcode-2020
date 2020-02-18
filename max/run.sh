#!/bin/bash

f=$1
if [ -z $f ]
then
  f="a";
fi

g++ -std=c++17 $f.cpp -o $f && echo "compiled successfully" && ./$f
