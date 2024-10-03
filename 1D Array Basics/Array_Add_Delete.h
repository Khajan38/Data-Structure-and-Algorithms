//Display, Append, Insert, Delete, Set
#pragma once
#include <stdio.h>
#include "Array_Struct.h"
#include "Array_Operations.h"

//Append : Time : O(array->length), Space : O(1)
void Display (Array array){
     printf("\n\nArray Elements : \n\n");
     for (int i = 0; i < array.length; i++)
          printf("\tElement %d : %d\n", i + 1, array.arr[i]);
}

//Append : Time : O(1) but resizing O(array->size), Space : O(1)
void Append (Array * array, int element){
     if (array->length == array->size){
          printf("\nOverflow... No more Insertions\n");
          char choice;
          printf("\n\nIncrease array size ? (Y/N) : ");
          scanf(" %c", &choice);
          if (choice == 'Y') Resize (array, array->size + 1);
          else return;
          printf("\n");
     }
     array->arr[array->length] = element;
     array->length++;
     printf("\n\tElement Appended successfully...");
}

//Insert : Time : O(array->size), Space : O(1)
void Insert (Array * array, int element, int position){
     if (position < 1 || position > array->length + 1){printf("\nPosition out of range..."); return;}
     else if (array->length == array->size){
          printf("\n\nOverflow... No more Insertions\n");
          char choice;
          printf("\n\nIncrease array size ? (Y/N) : ");
          scanf(" %c", &choice);
          if (choice == 'Y') Resize (array, array->size + 1);
          else return;
          printf("\n");
     }
     for (int i = array->length; i > position - 1; i--)
          array->arr[i] = array->arr[i-1];
     array->arr[position - 1] = element;
     array->length++;
     printf("\n\tElement Inserted successfully...");
}

//Delete : Time : O(array->size), Space : O(1)
void Delete (Array * array, int position){
     if (position < 1 || position > array->length){printf("\nPosition out of range..."); return;}
     for (int i = position - 1; i < array->length - 1; i++)
          array->arr[i] = array->arr[i+1];
     array->length--;
     printf("\n\tElement Deleted successfully...");
}

//Set : Time : O(1), Space : O(1)
void Set (Array * array, int element, int position){
     if (position < 1 || position > array->length){printf("\nPosition out of range..."); return;}
     array->arr[position - 1] = element;
     printf("\n\tElement Updated successfully...");
}