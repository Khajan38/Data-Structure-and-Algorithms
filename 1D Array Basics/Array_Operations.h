//Resize, Reverse, Left Shift, Right Shift, Rotate

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "Array_Struct.h"

//Resize -> Time : O(array->size), Space : O(new_size)
void Resize (Array *array, int new_size){
     //int * temp = realloc(array->arr, array->size*sizeof(int));
     int * temp = (int * ) malloc(new_size*sizeof(int));
     if (temp == NULL){
          printf("Failed to reallocate memory");
          return;
     }
     for (int i = 0; i < array->size; i++) temp[i] = array->arr[i];
     array->size = new_size;
     free(array->arr); array->arr = temp; temp = NULL; printf("\n");
     printf("Increased Array Size, Loading Append Window");
}

//Reverse -> Time : O(n), Space : O(1);
//This takes n/2 time in this Two Pointer Technique OR 
//We can create a new array copy reversed elements to it and initialize it to original taking O(n).
void Reverse (Array *array){
     for (int i = 0; i < array->length/2; i++){
          int temp = array->arr[array->length - i - 1];
          array->arr[array->length - i - 1] = array->arr[i];
          array->arr[i] = temp;
     }
}

//Left Shift-> Time : O(n), Space : O(1);
void Left_Shift (Array *array){
     for (int i = 0; i < array->length - 1; i++)
          array->arr[i] = array->arr[i + 1];
     array->arr[array->length - 1] = 0;
}

//Right Shift-> Time : O(n), Space : O(1);
void Right_Shift (Array *array){
     for (int i = array->length - 1; i > 0; i--)
          array->arr[i] = array->arr[i - 1];
     array->arr[0] = 0;
}