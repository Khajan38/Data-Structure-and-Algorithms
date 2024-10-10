#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
     char val;
     struct ListNode * next;
} ListNode;

ListNode * insertString (char * s){
     ListNode * head = NULL;
     for (int i = 0; s[i] != '\0'; i++){
          ListNode * temp = (ListNode *) malloc(sizeof(ListNode));
          temp->val = s[i];
          if (head == NULL){
               head = temp;
               head->next = NULL;
          }
          else {
               ListNode * tempHead = head;
               if (s[i] <= head->val){
                    temp->next = head;
                    head = temp;
                    continue;
               }
               while (tempHead->next != NULL && tempHead->next->val < s[i]) 
                    tempHead = tempHead->next;
               temp->next = tempHead->next;
               tempHead->next = temp;
          }
     }
     return head;
}

void display (ListNode * head){
     printf("\nLinked List : ");
     if (head == NULL) printf("Empty...");
     while (head != NULL){
          printf("%c, ", head->val);
          head = head->next;
     }
     printf("\b\b \n");
     return;
}

int main (){
     char s[100];
     printf("\nEnter the string : ");
     scanf(" %[^\n]", s);
     ListNode * head = insertString(s);
     display(head);
     while (head != NULL){
          ListNode * temp = head;
          head = head->next;
          free(temp);
     }
     return 0;
}