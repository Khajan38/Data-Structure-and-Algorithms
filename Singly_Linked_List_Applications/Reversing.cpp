#pragma once
#include "../Singly_Linked_List_Basics/ADT.h"

ListNode * reverse (ListNode * head){
     ListNode * prev = nullptr;
     while (head != nullptr){
          ListNode * next = head->next;
          head->next = prev;
          prev = head;
          head = next;
     }
     return prev;
}

//Here we have to create new Reversed Linked List
bool palindrome (ListNode * head){
     ListNode * revHead = nullptr, * tempHead = head, * prev = nullptr;
     while (tempHead != NULL){
          ListNode * temp = new ListNode;
          if (revHead == nullptr) revHead = temp;
          temp->val = tempHead->val;
          temp->next = prev;
          prev = temp;
          tempHead = tempHead->next;
     }
     while (revHead != NULL){
          if (revHead->val != head->val) return false;
          revHead = revHead -> next;
          head = head -> next;
     }
     return true;
}

bool palindrome (ListNode * head){
     ListNode * slow = head, * fast = head;
     if (head == NULL) return true;
     while (fast->next != NULL && fast->next->next != NULL){
          slow = slow->next;
          fast = fast->next->next;
     }
     fast = slow->next;
     slow->next = NULL; slow = fast;
     ListNode * prev = nullptr;
     while (fast != NULL){
          ListNode * next = fast->next;
          fast->next = prev;
          prev = fast;
          fast = next;
     }
     while (slow != NULL){
          if (slow->val != head->val) return false;
          slow = slow -> next;
          head = head -> next;
     }
     return true;
}