#!/bin/bash

rm -rf build/
mkdir build
cd build
cmake ../
make
./tests/LTC2943Tests
