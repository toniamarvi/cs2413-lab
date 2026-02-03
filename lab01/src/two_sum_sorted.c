#include "two_sum_sorted.h"

int two_sum_sorted(const int* nums, int n, int target, int* out_i, int* out_j) {
    if (!nums || !out_i || !out_j || n < 2) return 0;

    // TODO: implement rwo sum solution for sorted arrays.
    /* have two pointers, one at the beginning and one at the end, loop through the array and increment by one,
    if the sum of the values at the two pointers is too small, move left pointer right and vice versa if its too big */

    int left = 0;
    int right = n-1;

    for (int i=0;left<right;i++) {
        if (nums[left] + nums[right] == target) {
            *out_i = left;
            *out_j = right;
            return 1;
        } else if (nums[left] + nums[right] > target) {
            right--;
        } else if (nums[left] + nums[right] < target) {
            left++;
        }
    }

    return 0;
}
// think about the time complexity and space complexity of your solution

