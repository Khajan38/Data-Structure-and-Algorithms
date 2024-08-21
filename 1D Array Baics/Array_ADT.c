#include <stdio.h>
#include <stdlib.h>
#include "Array_Struct.h"
#include "Array_Add_Delete.h"
#include "Array_Operations.h"
#include "Array_Search.h"
#include "Array_Sort.h"
#include "Array_Elements_Operations.h"

const char *Menu_Items[] = {"Display Array Elements", "Append new element", "Insert new Element", "Delete an Element", "Set an Element", "Linear Search an Element", "Binary Search an Element", "Selection Sort and Algorithm", "Bubble Sort and Algorithm", "Insertion Sort and Algorithm","Get an Element", "Find Max Element", "Find Min Element", "Sum of Elements", "Average of Elements", "Product of Elements", "Reverse the Array", "Left Shift an Array", "Right Shift and Array", "Resize an Array", "Exit Array ADT"};

int main(){
     printf("\n\n\t\tARRAY ADT : INITIAL INSERTION WINDOW\n\n");
     int size;
     printf("Enter size of Array : "); scanf("%d", &size);
     printf("\nEnter Array Elements (Terminated by -1): \n\n");
     Array array = {size, 0, (int *) malloc(size * sizeof(int))};
     for (int a = 0, i = 0; ; i++){
          if (i == array.size){printf("\nOverflow... No more Insertions\n"); break;}
          printf("\tElement %d : ", ++array.length);
          scanf("%d", &a); 
          if (a != -1) array.arr[i] = a;
          else {array.length--; break;}
     }
     line;
     printf("\t\tARRAY ADT : INITIAL DISPLAY WINDOW");
     Display(array);
     line;
     while (1){
          printf("\t\tARRAY ADT : MAIN MENU\n\n");
          for (int i = 0; i < 21; i++)
               printf("%c. %s\n", 'A'+i, Menu_Items[i]);
          char choice; printf("\nEnter your choice : "); scanf(" %c", &choice);
          if (choice >= 'A' && choice < 'A'+ 21) line;
          switch (choice){
               case 'A': 
                    printf("\t\tARRAY ADT : INITIAL DISPLAY WINDOW");
                    Display(array);
                    line; break;
               case 'B': {
                    printf("\t\tARRAY ADT : APPEND WINDOW\n\n");
                    int element;
                    printf("Enter the element : "); scanf("%d", &element);
                    Append(&array, element);
                    line; break;
               }
               case 'C':{
                    printf("\t\tARRAY ADT : INSERT WINDOW\n\n");
                    int element, position;
                    printf("Enter the element : ");  scanf("%d", &element);
                    printf("Enter the position : ");  scanf("%d", &position);
                    Insert(&array, element, position);
                    line; break;
               }
               case 'D':{
                    printf("\t\tARRAY ADT : DELETE WINDOW\n\n");
                    int position;
                    printf("Enter the position : ");  scanf("%d", &position);
                    Delete(&array, position);
                    line; break;
               }
               case 'E':{
                    printf("\t\tARRAY ADT : UPDATE WINDOW\n\n");
                    int element, position;
                    printf("Enter the element : ");  scanf("%d", &element);
                    printf("Enter the position : ");  scanf("%d", &position);
                    Set(&array, element, position);
                    line; break;
               }
               case 'F':{
                    printf("\t\tARRAY ADT : LINEAR SEARCH WINDOW\n\n");
                    int element;
                    printf("Enter the element : ");  scanf("%d", &element);
                    int position = Linear_Search(&array, element);
                    if (position == 0)  printf("\n\t%d is not present in the array", element);
                    else printf("\n\t%d found at Position : %d", element, position);
                    line; break;
               }
               case 'G':{
                    printf("\t\tARRAY ADT : BINARY SEARCH WINDOW\n\n");
                    int element;
                    printf("Enter the element : ");  scanf("%d", &element);
                    int position = Binary_Search(&array, element);
                    if (position == 0)  printf("\n\t%d is not present in the array", element);
                    else printf("\n\t%d found at Position : %d", element, position);
                    line; break;
               }
               case 'H':
                    printf("\t\tARRAY ADT : SELECTION SORT WINDOW\n\n");
                    printf("Applying Selection Sort...\n");\
                    Selection_Sort(&array);
                    printf("\nArray Sorted...");
                    Display(array);
                    line; break;
               case 'I':
                    printf("\t\tARRAY ADT : BUBBLE SORT WINDOW\n\n");
                    printf("Applying Bubble Sort...\n");\
                    Bubble_Sort(&array);
                    printf("\nArray Sorted...");
                    Display(array);
                    line; break;
               case 'J':
                    printf("\t\tARRAY ADT : INSERTION SORT WINDOW\n\n");
                    printf("Applying Insertion Sort...\n");\
                    Insertion_Sort(&array);
                    printf("\nArray Sorted...");
                    Display(array);
                    line; break;
               case 'K':{
                    printf("\t\tARRAY ADT : GET ELEMENT WINDOW\n\n");
                    int position;
                    printf("Enter the position : ");  scanf("%d", &position);
                    int element = Get(array, position);
                    printf("\n\n\tFetching the array for Details...");
                    if (element != 0) printf("\n\nElement : %d found at position : %d", element, position);
                    else printf("\n\nPosition out of bound...");
                    line; break;
               }
               case 'L':
                    printf("\t\tARRAY ADT : MAXIMUM WINDOW\n\n");
                    Max(array);
                    line; break;
               case 'M':
                    printf("\t\tARRAY ADT : MINIMUM WINDOW\n\n");
                    Min(array);
                    line; break;
               case 'N':{
                    printf("\t\tARRAY ADT : SUM OF ELEMENTS WINDOW\n\n");
                    int sum = Sum(array);
                    if (sum != INT_MAX) printf("The sum of elements of array is : %d", sum);
                    line; break;
               }
               case 'O':{
                    printf("\t\tARRAY ADT : AVERAGE OF ELEMENTS WINDOW\n\n");
                    float avg = Average(array);
                    if (avg != INT_MAX) printf("The sum of elements of array is : %d", avg);
                    line; break;
               }
               case 'P':{
                    printf("\t\tARRAY ADT : PRODUCT OF ELEMENTS WINDOW\n\n");
                    int product = Product(array);
                    if (product != INT_MAX) printf("The product of elements of array is : %d", product);
                    line; break;
               }
               case 'Q':
                    printf("\t\tARRAY ADT : REVERSE WINDOW\n\n");
                    Reverse(&array);
                    printf("Reversed the array...");
                    line; break;
               case 'R':
                    printf("\t\tARRAY ADT : LEFT SHIFT WINDOW\n\n");
                    Left_Shift(&array);
                    printf("Left Shifted the array...");
                    line; break;
               case 'S':
                    printf("\t\tARRAY ADT : RIGHT SHIFTED WINDOW\n\n");
                    Right_Shift(&array);
                    printf("Right Shifted the array...");
                    line; break;
               case 'T':{
                    printf("\t\tARRAY ADT : ARRAY RESIZE WINDOW\n\n");
                    int new_size;
                    printf("Enter no. of elements : ");  scanf("%d", &new_size);
                    Resize(&array, new_size);
                    printf("\nArray Resized...");
                    line; break;
               }
               case 'U':
                    exit(3);
               default :
                    printf("\n\tEnter a valid request...");
                    line;
          }
     }
     return 0;
}