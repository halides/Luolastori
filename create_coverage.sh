#!/bin/bash
make clean
make
make test
./test_luolastori
gcov luolastori
echo "check luolastori.cpp.gcov for the coverage results"
