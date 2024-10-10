#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int linkedListCapacity = 100; //Max Capacity
int linkedListCount = 0;

typedef struct ListNode{
     int val;
     struct ListNode * next;
} ListNode;

bool isEmpty (ListNode * head){
     return (head == NULL);
}

ListNode * createNode (ListNode * head, int element){
     ListNode * temp = (ListNode *) malloc (sizeof(ListNode));
     temp->val = element;
     temp->next = NULL;
     if (head == NULL) return temp;
     if (linkedListCount == linkedListCapacity) {
          printf("Overflow...");
          return head;
     }
     ListNode * returnHead = head;
     while (head->next != NULL) head = head->next;
     head->next = temp;
     ++linkedListCount;
     return returnHead;
}