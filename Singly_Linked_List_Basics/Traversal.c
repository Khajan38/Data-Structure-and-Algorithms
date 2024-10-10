#pragma once
#include "ADT.c"

void display (ListNode * head){
     printf("\nLinked List : ");
     if (head == NULL) printf("Empty.....");
     while (head != NULL) printf("%d, ", head->val);
     printf("\b\b \n");
}

//Returns second middle element in even Linked List
int middle1 (ListNode * head){
     if (head == NULL){
          printf("\nNo elements in the Linked List...");
          return INT_MIN;
     }
     ListNode * slow = head, * fast = head;
     while (fast != NULL && fast->next != NULL){
          slow = slow->next;
          fast = fast->next->next;
     }
     return slow->val;
}

//Returns first middle element in even Linked List
int middle2 (ListNode * head){
     if (head == NULL){
          printf("\nNo elements in the Linked List...");
          return INT_MIN;
     }
     ListNode * slow = head, * fast = head;
     while (fast->next != NULL && fast->next->next != NULL){
          slow = slow->next;
          fast = fast->next->next;
     }
     return slow->val;
}

int totalLength (ListNode * head){
     int length = 0;
     while (head != NULL) {
          ++length;
          head = head->next;
     }
     return length;
}