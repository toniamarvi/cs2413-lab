/*
 * Assignment 2 / Question 1 / student.c
 * ------------------------------------------------------------
 * Search in a Binary Search Tree (BST)
 *
 * Implement:
 *   struct TreeNode* bstSearch(struct TreeNode* root, int target);
 *
 * Rules:
 * - Return a pointer to the node with value == target, else NULL.
 * - Do NOT allocate new nodes.
 * - Do NOT modify the tree.
 * - Do NOT print anything.
 *
 * Build/Run (from Assignment2 folder):
 *   make run1
 */

#include <stddef.h>  // NULL

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* bstSearch(struct TreeNode* root, int target) {
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
    (void)root;
    (void)target;
    return NULL;
}
