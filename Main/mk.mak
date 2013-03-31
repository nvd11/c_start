#!/bin/bash

make cleanall

#############################################
make sort.o
make array_funcs.o
make malloc_1.o
make array.o
make char_array.o
make bisearch.o
make bit32_64.o
make pointer1.o 
make struct1.o 

#############################################

make main.o
make main
make clean
