/*
Question 2: Kth Largest Element in an Array

Description:
Given an integer array nums and an integer k, return the kth largest
element in the array.

Note that it is the kth largest element in sorted order, not the kth
distinct element.

For this lab, you should solve the problem using a heap-based idea.

Function:
int findKthLargest(int* nums, int numsSize, int k);

Notes:
- You may assume 1 <= k <= numsSize.
- Repeated values still count.
- A min-heap of size k is a good way to solve this efficiently.

Example 1:
Input:  nums = [3, 2, 1, 5, 6, 4], k = 2
Output: 5

Example 2:
Input:  nums = [3, 2, 3, 1, 2, 4, 5, 5, 6], k = 4
Output: 4

Hint:
Keep only the k largest elements seen so far in a min-heap.
The root of that heap will be the kth largest element.
*/

#include <stdlib.h>

static void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

static void heapifyUp(int* heap, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[index] < heap[parent]) {
            swap(&heap[index], &heap[parent]);
            index = parent;
        } else {
            break;
        }
    }
}

static void heapifyDown(int* heap, int size, int index) {
    while (1) {
        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        
        if (left < size && heap[left] < heap[smallest]) {
            smallest = left;
        }
        if (right < size && heap[right] < heap[smallest]) {
            smallest = right;
        }
        
        if (smallest != index) {
            swap(&heap[index], &heap[smallest]);
            index = smallest;
        } else {
            break;
        }
    }
}

int findKthLargest(int* nums, int numsSize, int k) {
    // Allocate min-heap of size k
    int* heap = (int*)malloc(k * sizeof(int));
    int heapSize = 0;
    
    for (int i = 0; i < numsSize; i++) {
        if (heapSize < k) {
            // Heap not full yet, just insert
            heap[heapSize] = nums[i];
            heapifyUp(heap, heapSize);
            heapSize++;
        } else if (nums[i] > heap[0]) {
            // Current element is larger than smallest in heap
            // Replace root and heapify down
            heap[0] = nums[i];
            heapifyDown(heap, k, 0);
        }
        // If nums[i] <= heap[0], skip it (not in top k)
    }
    
    int result = heap[0];
    free(heap);
    return result;
}