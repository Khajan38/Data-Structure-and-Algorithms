//Sorting Teachniques

#pragma once
#include <stdio.h>
#include <stdbool.h>
#include "Array_Struct.h"

//Selection Sort -> Time : O(n^2), Space : O(1)
//Here, we find the minimum element and swaps it with first element
void Selection_Sort (Array *array){
     for (int i = 0; i < array->length - 1; i++){
          int minIndex = i;
          for (int j = i+1; j < array->length; j++)
               if (array->arr[j] < array->arr[minIndex]) minIndex = j;
          if (minIndex != i){
               int temp = array->arr[i];
               array->arr[i] = array->arr[minIndex];
               array->arr[minIndex] = temp;
          }
     }
}

//Bubble Sort -> Time : O(n^2), Space : O(1)
//Here, swap every adjustant element and makes largest element at its place
void Bubble_Sort (Array *array){
     for (int i = 0; i < array->length - 1; i++){
          bool sorted = true;
          for (int j = 0; j < array->length - i - 1; j++)
               if (array->arr[j] > array->arr[j+1]){
                    int temp = array->arr[j];
                    array->arr[j] = array->arr[j + 1];
                    array->arr[j + 1] = temp;
                    sorted = false;
               }
          if (sorted) break;
     }
}

//Insertion Sort -> Time : O(n^2), Space : O(1)
//Here, swap occurs to make sort in smaller steps (sorted subarrys) by placing elements at correct position
void Insertion_Sort (Array *array){
     for (int i = 1; i < array->length; i++){
          int element = array->arr[i], j = i - 1;
          for (; j >= 0 && array->arr[j] > element; j++)
               array->arr[j + 1] = array->arr[j];
          array->arr[j + 1] = element;
     }
}