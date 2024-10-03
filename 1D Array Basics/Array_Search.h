//Searching Techniques

#pragma once
#include <stdio.h>
#include "Array_Struct.h"

//Linear Search -> Time : O(n), Space : O(1)
int Linear_Search (Array *array, int element){
     for (int i = 0; i < array->length; i++)
          if (array->arr[i] == element) return i+1;
     return 0;
}

//Linear Search (Transposition) -> Time : O(n), Space : O(1)
//This is used for Linear Search when elements that are repetedly searched moves to the front in array thus in next search it takes lower time
int Linear_Search_Transposition (Array *array, int element){
     for (int i = 0; i < array->length; i++)
          if (array->arr[i] == element){
               int temp = array->arr[i - 1];
               array->arr[i - 1] = array->arr[i];
               array->arr[i] = temp;
               return i;
          }
     return 0;
}

//Linear Search (Move to Front/Head) -> Time : O(n), Space : O(1)
//It is used when we want that a particular that will be most serached will move to first and hence in next search takes O(1) complexity
int Linear_Search_Move_To_Head (Array *array, int element){
     for (int i = 0; i < array->length; i++)
          if (array->arr[i] == element){
               int temp = array->arr[0];
               array->arr[0] = array->arr[i];
               array->arr[i] = temp;
               return 1;
          }
     return 0;
}

//Binary Search -> Time : O(log(n)), Space : O(1)
//Always used for Sorted Arrays and reduces searches to half so complexity comes by order of log
int Binary_Search (Array *array, int element){
     for (int i = 0, j = array->length - 1; i <= j;){
          int middle = (i + j)/2;
          if (array->arr[middle] == element) return middle + 1;
          else if (array->arr[middle] > element) j = middle - 1;
          else i = middle + 1;
     }
     return 0;
}