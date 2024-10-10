#pragma once
#include "ADT.c"

ListNode * deletion (ListNode * head, int element){
     if (head == NULL){
          printf("\nUnderflow...");
          return head;
     }
     ListNode * returnHead = head;
     if (head->val == element){
          returnHead = head->next;
          free(head);
          --linkedListCount;
          return returnHead;
     }
     while (head->next != NULL){
          if (head->next->val == element){
               ListNode * temp = head->next;
               head->next = head->next->next;
               free(temp);
               --linkedListCount;
               return returnHead;
          }
          head = head->next;
     }
     printf("\nElement not present in the Linked List...");
     return returnHead;
}

ListNode * deleteAtHead (ListNode * head){
     if (head == NULL){
          printf("\nUnderflow...");
          return head;
     }
     ListNode * returnHead = head->next;
     free(head);
     --linkedListCount;
     return returnHead;
}

ListNode * deleteAtEnd (ListNode * head){
     if (head == NULL){
          printf("\nUnderflow...");
          return head;
     }
     if (head->next == NULL) {
          free(head);
          --linkedListCount;
          return NULL;
     }
     ListNode * returnHead = head;
     while (head->next->next != NULL) head = head->next;
     ListNode * temp = head->next;
     head->next = NULL;
     free(temp);
     --linkedListCount;
     return returnHead;
}

ListNode * deleteAtMiddle (ListNode * head){
     if (head == NULL){
          printf("\nUnderflow...");
          return head;
     }
     if (head->next == NULL){
          free(head);
          --linkedListCount;
          return NULL;
     }
     ListNode * fast = head, * slow = head;
     while (fast->next->next != NULL && fast->next->next->next != NULL){
          slow = slow->next;
          fast = fast->next->next;
     }
     fast = slow->next;
     slow->next = fast->next;
     free(fast);
     --linkedListCount;
     return head;
}