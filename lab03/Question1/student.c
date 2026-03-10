// Question1/student.c
// ------------------------------------------------------------
// CS Lab03 - Reverse Linked List 
//
// TODO:
//   Implement reverseList(head) to reverse a singly linked list.
//
// Rules:
// - Do not allocate new nodes.
// - Do not use recursion.
// - Return the new head pointer.
// ------------------------------------------------------------

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include "student.h"

struct ListNode* reverseList(struct ListNode* head) {
    // TODO: implement
    // Hints (optional):
    // - Keep track of previous and current pointers.
    // - Iterate until current becomes NULL.

    struct ListNode *prev = NULL;
    struct ListNode *curr = head;
    struct ListNode *next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    // Continue searching while we still have nodes
    while (root != NULL) {

        // Case 1: Found the target
        if (root->val == target) {
            return root;
        }

        // Case 2: Target is smaller → go left
        else if (target < root->val) {
            root = root->left;
        }

        // Case 3: Target is larger → go right
        else {
            root = root->right;
        }
    }

    // If we reach NULL, the value wasn't found
    return NULL;

    return prev;
}