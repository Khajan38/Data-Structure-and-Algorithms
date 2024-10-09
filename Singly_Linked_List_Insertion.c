#pragma once
#include "Singly_Linked_List_ADT.c"

ListNode * insertion (ListNode * head, int element, int position){
     int count = 0;
     ListNode * ele = (ListNode *) malloc (sizeof(ListNode)), * returnHead = head;
     ele->val = element;
     if (position == 1){
          ele->next = head;
          return ele;
     }
     while (head != NULL){
          ++count;
          if (count == position - 1){
               ele->next = head->next;
               head->next = ele;
               return returnHead;
          }
          head = head->next;
     }
     printf("\nOverflow...");
     return returnHead;
}

ListNode * insertionAtBegin (ListNode * head, int element){
     ListNode * ele = (ListNode *) malloc (sizeof(ListNode));
     ele->val = element;
     ele->next = head;
     return ele;
}

ListNode * insertionAtEnd (ListNode * head, int element){
     ListNode * ele = (ListNode *) malloc (sizeof(ListNode)), * returnHead = head;
     ele->val = element;
     ele->next = NULL;
     if (head == NULL) return ele;
     while (head->next != NULL) head = head->next;
     head->next = ele;
     return returnHead;
}

ListNode * insertionAtMiddle (ListNode * head, int element){
     ListNode * ele = (ListNode *) malloc (sizeof(ListNode)), * returnHead = head;
     ele->val = element;
     if (head == NULL) return ele;
     ListNode * slow = head, * fast = head;
     while (fast->next != NULL && fast->next->next != NULL){
          slow = slow->next;
          fast = fast->next;
     }
     ele->next = slow->next;
     slow->next = ele;
     return returnHead;
}