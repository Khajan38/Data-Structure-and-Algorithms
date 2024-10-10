#include "Stack_Basics\Stack_ADT_Linked_List.c"

int operation (char a, char b, char operator){
     int inta = a - '0', intb = b - '0';
     switch (operator){
          case '+': return inta + intb + '0';
          case '-': return inta - intb + '0';
          case '*': return inta * intb + '0';
          case '/': return inta / intb + '0';
     }
}

int postfixSolve (char * postfix){
     Stack * stack = (Stack *) malloc(sizeof(Stack));
     stack->head = NULL;
     stack->capacity = INT_MAX;
     stack->top = -1;
     for (int i = 0; postfix[i] != '\0'; i++){
          char ch = postfix[i];
          if (ch >= '0' && ch <= '9') push(stack, ch);
          else {
               char a = peek(stack);
               pop(stack);
               char result = operation(a, peek(stack), ch);
               pop(stack);
               push(stack, result);
          }
     }
     int result = peek(stack) - '0';
     free(stack->head); free(stack);
     return result;
}