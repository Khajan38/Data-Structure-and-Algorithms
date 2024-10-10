#include "Stack_Basics\Stack_ADT_Linked_List.c"

int precedence(char c) {
     switch (c) {
     case '+':
     case '-':
          return 1;
     case '*':
     case '/':
     case '%':
          return 2;
     case '^':
          return 3;
     default:
          return 0;
     }
}

bool leftToRightAssociativity(char c) {
     if (c == '^')
          return false; // Right-to-left associativity for '^'
     return true;
}

char * infixToPostfix (char * infix){
     char * postfix = (char *) malloc (100*sizeof(char));
     int index = 0;
     Stack * stack = (Stack *) malloc(sizeof(Stack));
     stack->head = NULL;
     stack->top = -1;
     stack->capacity = INT_MAX;
     for (int i = 0; infix[i] != '\0'; i++){
          char ch = infix[i];
          if (ch == '(') push(stack, ch); 
          else if (ch == ')'){
               while (peek(stack) != '('){
                    postfix[index++] = peek(stack);
                    pop(stack);
               }
               pop(stack);
          }
          else if ((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || ch == ' ')
               postfix[index++] = ch;
          else {
               while (!isEmpty(stack) && ((precedence(peek(stack)) > precedence(ch)) ||  (precedence(peek(stack)) == precedence(ch) && leftToRightAssociativity(ch)))){
                    postfix[index++] = peek(stack);
                    pop(stack);
               }
               push(stack, ch);
          }
     }
     while (!isEmpty(stack)){
          postfix[index++] = peek(stack);
          pop(stack);
     }
     postfix[index] = '\0';
     free(stack);
     return postfix;
}

int main (){
     char * infix = (char *) malloc(100*sizeof(char));
     printf("\nEnter the Infix Expression : ");
     scanf(" %[^\n]", infix);
     char * postfix = infixToPostfix(infix);
     printf("Postfix Expression : %s\n", postfix);
     free(infix);
     free(postfix);
     return 0;
}