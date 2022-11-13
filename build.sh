#!/bin/sh

set -xe

clang++ -Wall -Wextra -pedantic -std=c++17 -o main *.cpp
