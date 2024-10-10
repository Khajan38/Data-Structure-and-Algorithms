#pragma once
#include "../Singly_Linked_List_Basics/ADT.h"

//Binary Search isn't applied on Singly Linked Lists as even if applied it further increases Time Complexity
int linearSearch (ListNode * head, int element){
     int count {0};
     while (head != NULL){
          ++count;
          if (head -> val == element) return count;
          head = head -> next;
     }
     return 0;
}