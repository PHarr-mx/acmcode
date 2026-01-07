#!/bin/bash
g++-13 $1.cpp -o $1 -g -O2 -std=c++20 \
-Wall -fsanitize=undefined -fsanitize=address \
&& echo compile_successfully >&2 && ./$1
