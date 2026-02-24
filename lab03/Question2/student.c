// Question2/student.c
// ------------------------------------------------------------
// CS Lab03 - Swap Nodes in Pairs 
//
// TODO:
//   Implement swapPairs(head) to swap every two adjacent nodes.
//
// Rules:
// - Do not allocate new nodes.
// - Do not swap values; swap nodes (rewire pointers).
// - Return the new head pointer.
// ------------------------------------------------------------
#include "student.h"

struct ListNode* swapPairs(struct ListNode* head) {
      // TODO: implement
      struct ListNode dummy;
      struct ListNode *prev = &dummy;
      dummy.next = head;

      while (prev->next != NULL && prev->next->next != NULL) {
            struct ListNode* a = prev->next;      // first in pair
            struct ListNode* b = a->next;         // second in pair

            // swap
            a->next = b->next;
            b->next = a;
            prev->next = b;

            // move prev to end of swapped pair
            prev = a;
      }
      return dummy.next;
}