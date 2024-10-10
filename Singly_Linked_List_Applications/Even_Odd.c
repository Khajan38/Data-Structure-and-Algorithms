#include <stdio.h>
#include <stdlib.h>

//Given a Linked List, we have to arrange it such that all even arrange in one end of Linked list while odd at other end in ascending order.

typedef struct ListNode {
     int val;
     struct ListNode * next;
} ListNode;

ListNode * ascendingInsertion (ListNode * element, ListNode * head){
     if (head == NULL) return element;
     ListNode * tempHead = head;
     if (head->val >= element->val){
          element->next = head;
          return element;
     }
     while (tempHead->next != NULL && tempHead->next->val < element->val)
          tempHead = tempHead->next;
     element->next = tempHead->next;
     tempHead->next = element;
     return head;
}

ListNode * arrange (ListNode * head){
     if (head == NULL || head->next == NULL) return head;
     ListNode * evenHead = NULL, *oddHead = NULL;
     while (head != NULL){
          ListNode * next = head->next;
          head->next = NULL;
          if (head->val % 2 == 0) evenHead = ascendingInsertion(head, evenHead);
          else oddHead = ascendingInsertion(head, oddHead);
          head = next;
     }
     if (evenHead == NULL) return oddHead;
     if (oddHead == NULL) return evenHead;
     ListNode * returnHead = evenHead;
     while (evenHead->next != NULL) evenHead = evenHead->next;
     evenHead->next = oddHead;
     return returnHead;
}