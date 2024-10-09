#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ListNode{
     int val;
     struct ListNode * next;
} ListNode;

bool isEmpty (ListNode * head){
     return (head == NULL);
}