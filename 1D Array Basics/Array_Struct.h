#pragma once
#include <stdio.h>

#define line printf( "\n\n=====================================================================================================================================\n\n")

typedef struct Array {
     //Data Members : space, size, length
     int size, length; //size = 10 ang length = 0 for empty array
     int * arr; //space is allocated as arr
} Array;