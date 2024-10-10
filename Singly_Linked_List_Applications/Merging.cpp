#pragma once
#include "../Singly_Linked_List_Basics/ADT.h"

//Merging is making making 2 linked lists in a Single Sorted List
ListNode * merge (ListNode * head1, ListNode * head2){
     ListNode * mergeHead = NULL, *returnHead = NULL;
     while (head1 != NULL && head2 != NULL){
          if (head1->val <= head2->val){
               if (returnHead == NULL){returnHead = head1; mergeHead = returnHead;}
               else mergeHead->next = head1;
               head1 = head1->next;
          }
          else{
               if (returnHead == NULL){returnHead = head2; mergeHead = returnHead;}
               else mergeHead->next = head2;
               head2 = head2->next;
          }
     }
     if (head1 != NULL) mergeHead->next = head1;
     if (head2 != NULL) mergeHead->next = head2;
     return returnHead;
}