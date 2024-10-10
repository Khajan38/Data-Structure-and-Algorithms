#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Stack {
     int * arr;
     int top, capacity;
} Stack;

bool isEmpty (Stack * stack){
     return (stack->top == -1);
}

bool isFull (Stack * stack){
     return (stack->top == stack->capacity - 1);
}

void push (Stack * stack, int element){
     if (isFull(stack)){
          printf("\nOverflow...");
          return;
     }
     stack->arr[++(stack->top)] = element;
     return;
}

void pop (Stack * stack){
     if (isEmpty(stack)){
          printf("\nUnderflow...");
          return;
     }
     --(stack->top);
     return;
}

int peek (Stack * stack){
     if (isEmpty(stack)){
          printf("\nStack is empty...");
          return -1;
     }
     return stack->arr[stack->top];
}

void display (Stack * stack){
     printf("\nStack : ");
     if (isEmpty(stack)) printf("\nEmpty...");
     for (int i = 0; i <= stack->top; i++)
          printf("%d, ", stack->arr[i]);
     printf("\b\b \n");
     return;
}

int main (){
     Stack * stack = (Stack *) malloc (sizeof (Stack));
     printf("\nEnter the capacity of the stack : ");
     scanf("%d", &(stack->capacity));
     stack->top = -1;
     stack->arr = (int *) malloc (stack->capacity*sizeof(int));
     //Operations here
     free(stack->arr);
     free(stack);
     return 0;
}