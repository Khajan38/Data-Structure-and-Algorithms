//Get, Min, Max, Sum, Avg, Product

#include <stdio.h>
#include <stdlib.h>
#include "Array_Struct.h"

//Get/Retrieve -> Time : O(1), Space : O(1)
int Get(Array array, int position){
     if (position < 1 || position > array.length){printf("\nPosition out of range..."); return 0;}
     return array.arr[position - 1];
}

//Max and Second Largest -> Time : O(array->length), Space : O(1)
void Max(Array array){
     if(array.length == 0){printf("\nNo elements present in Array..."); return;}
     else if (array.length == 1){printf("\nArray has only 1 element which is largest : %d", array.arr[0]); return;}
     int largest = 0, second_largest = 1;
     for (int i = 1; i < array.length; i++){
          if (array.arr[largest] < array.arr[i]){second_largest = largest; largest = i;}
          else if (array.arr[second_largest] < array.arr[i])second_largest = i;
     }
     printf("\nThe second largest element is : %d and largest element is : %d", array.arr[second_largest], array.arr[largest]);
}

//Min and Second Lowest -> Time : O(array->length), Space : O(1)
void Min(Array array){
     if(array.length == 0){printf("\nNo elements present in Array..."); return;}
     else if (array.length == 1){printf("\nArray has only 1 element which is lowest : %d", array.arr[0]); return;}
     int lowest = 0, second_lowest = 1;
     for (int i = 1; i < array.length; i++){
          if (array.arr[lowest] > array.arr[i]){second_lowest = lowest; lowest = i;}
          else if (array.arr[second_lowest] > array.arr[i])second_lowest = i;
     }
     printf("\nThe second lowest element is : %d and lowest element is : %d", array.arr[second_lowest], array.arr[lowest]);
}

//Sum of Elements -> Time : O(array->length), Space : O(1)
int Sum(Array array){
     if(array.length == 0){printf("\nNo elements present in Array..."); return INT_MAX;}
     int sum = 0;
     for (int i = 0; i < array.length; i++) sum += array.arr[i];
     return sum;
}

//Average of Elements -> Time : O(array->length), Space : O(1)
float Average(Array array){
     float avg = (float) Sum(array);
     avg /= (array.length)? array.length : 1;
     return avg;
}

//Product of Elements -> Time : O(array->length), Space : O(1)
int Product(Array array){
     if(array.length == 0){printf("\nNo elements present in Array..."); return INT_MAX;}
     int product = 1;
     for (int i = 0; i < array.length; i++) product *= array.arr[i];
     return product;
}