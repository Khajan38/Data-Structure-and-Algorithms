#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ListNode {
     char val;
     struct ListNode * next;
} ListNode;

typedef struct Stack {
     ListNode * head;
     int top, capacity;
} Stack;

bool isEmpty (Stack * stack){
     return (stack->head == NULL);
}

bool isFull (Stack * stack){
     return (stack->top == stack->capacity - 1);
}

void push (Stack * stack, char element){
     if (isFull(stack)){
          printf("\nOverflow...");
          return;
     }
     ListNode * temp = (ListNode *) malloc(sizeof (ListNode));
     temp->val = element;
     temp->next = stack->head;
     stack->head = temp;
     ++(stack->top);
     return;
}

void pop (Stack * stack){
     if (isEmpty(stack)){
          printf("\nUnderflow...");
          return;
     }
     ListNode * temp = stack->head;
     stack->head = stack->head->next;
     --(stack->top);
     free(temp);
     return;
}

char peek (Stack * stack){
     if (isEmpty(stack)){
          printf("\nStack is Empty...");
          return -1;
     }
     return stack->head->val;
}

/*
int main (){
     Stack * stack = (Stack *) malloc (sizeof(Stack));
     stack->head = NULL;
     stack->top = -1;
     printf("\nEnter the number of elements in Stack : ");
     scanf("%d", &(stack->capacity));
     //Operations here
     while (stack->head != NULL){
          ListNode * temp = stack->head;
          stack->head = stack->head->next;
          free(temp);
     }
     free(stack);
     return 0;
}
*/