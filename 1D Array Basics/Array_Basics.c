#include <stdio.h>
#include <stdlib.h>
int main(){

     //Array Declarations and Initializations

     int a [] = {15, 28, 33, 46}; /*Declaration + Compile Time Initialization without size, Creates array size same as no. of elements*/
     int b [5] = {1, 2, 3, 4}; /*Declaration + Compile Time Initialization + Here all remaining elements are set 0, only for this method*/
     char c [5]; //Declaration of Array
     c[0] = 'a';//Compile Time Initialization
     c[1] = 56; printf("\n");
     for (int i = 1; i <= 3; i++){
          printf("Enter a character for value of element %d : ", i+2);
          scanf(" %c", &c[i+1]); //Run Time Initialization
     }// This “ %c” is used to consume all the whitespaces and newline and take next input a non-whitespace character.
     int n;
     printf("\nEnter the number of element sin array : "); //Run time asking for total number of elements of array
     int d[n]; //Dynamic Array Declaration
     int * e = (int *) malloc(n * sizeof(int)); //Used in C to create dynamic arrays in Heap
     free(e);

     //Traversing and Displaying Array Elements -> Time : O(n), Space : O(1)

     printf("\nElement 1, 5 of Array a is : %d, %d\n", a[0], a[4]); //Accessing a element
     for (int m = 0; m < 5; m++)
          printf("\nElement %d : %d, %c; Address %d : %u, %u", m + 1, c[m], c[m], m + 1, &(c[m]), &(c[m])); 

     //Increasing Array Size

     int * e = (int *) malloc(4 * sizeof(int)); e[0] = 15; e[1] = 28; e[2] = 33; e[3] = 46; //Old array
     int new_size = 10; //Let old array be e = {15, 28, 33, 46}
     int * f = (int *) malloc(new_size * sizeof(int)); //New array f
     for (int i = 0; i < 4; i++) f[i] = e[i]; //Shifiting onld array elements to new array
     free(e); e = f; f = NULL;//Changing e address as f
     free(e);

     int * e = (int *) malloc(4 * sizeof(int)); e[0] = 15; e[1] = 28; e[2] = 33; e[3] = 46; //Old array
     e = realloc(e, 6*sizeof(int)); e[4] = 31; e[5] = 40; //Using realloc ro increase size of Array e
     for (int i = 0; i < 6; i++) printf("%d ", e[i]);

     //Making Multi-Dimensional Arrays
     int rows = 2, columns = 3;
     int multi_2D [rows][columns]; //A 2D Array
     int multi_3D [2][3][4]; //A 3D Array
     int D2_1 [][4] = {{1, 2, 3, 4}, {5, 3, 2}}; //Columns are must to be given, Rows are detected by initialization, which is now must.
     int * D2_2[2] = (int (*) [2]) malloc(2 * sizeof(int [3])); //Dynamic 2-D Array Creation
     free (D2_2);

     //Initializing values to 2D Array
     for (int i = 0; i < rows; i++)
          for (int j = 0; j < columns; j++)
               scanf("%d", &multi_2D[i][j]);

     return 0;
}