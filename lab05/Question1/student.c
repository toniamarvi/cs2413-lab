/*
Question 1: Two Sum

Description:
Given an array of integers nums and an integer target, return the indices
of the two numbers such that they add up to target.

You may assume that each input has exactly one solution, and you may not
use the same element twice.

For this lab, you should solve the problem using a hash-based idea.

Function:
int* twoSum(int* nums, int numsSize, int target, int* returnSize);

Notes:
- Return a dynamically allocated array of size 2.
- Set *returnSize = 2 before returning.
- The returned array will be freed by the caller.

Example:
Input:  nums = [2, 7, 11, 15], target = 9
Output: [0, 1]

Hint:
As you scan the array, for each nums[i], think about whether the value
(target - nums[i]) has already appeared before.
*/

#include <stdlib.h>

/*
Optional helper structure for a hash table entry.

You may use this structure if you want to build your own hash table.
key   -> the number from the array
value -> the index of that number
*/
#include <stdlib.h>

typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;

#define TABLE_SIZE 1000

static int hash(int key) {
    // Handle negative numbers by taking absolute value then mod
    int h = key % TABLE_SIZE;
    if (h < 0) h += TABLE_SIZE;
    return h;
}

static void insert(Node* table[], int key, int value) {
    int idx = hash(key);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = table[idx];  // Insert at head of chain
    table[idx] = newNode;
}

static int find(Node* table[], int key, int* value) {
    int idx = hash(key);
    Node* curr = table[idx];
    while (curr != NULL) {
        if (curr->key == key) {
            *value = curr->value;
            return 1;  // Found
        }
        curr = curr->next;
    }
    return 0;  // Not found
}

static void freeTable(Node* table[]) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* curr = table[i];
        while (curr != NULL) {
            Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    // Create and initialize hash table
    Node* table[TABLE_SIZE] = {NULL};
    
    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        int foundIndex;
        
        // Check if complement exists in table
        if (find(table, complement, &foundIndex)) {
            // Found the pair!
            int* result = (int*)malloc(2 * sizeof(int));
            result[0] = foundIndex;
            result[1] = i;
            *returnSize = 2;
            freeTable(table);
            return result;
        }
        
        // Insert current number and its index
        insert(table, nums[i], i);
    }
    
    // No solution found (shouldn't happen per problem statement)
    freeTable(table);
    *returnSize = 0;
    return NULL;
}