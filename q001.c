#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * https://leetcode-cn.com/problems/two-sum/description/
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *twoSum(int* nums, int numsSize, int target) {
    for (int idx0 = 0; idx0 < numsSize; ++idx0) {
        for (int idx1 = idx0 + 1; idx1 < numsSize; ++idx1) {
            if (*(nums + idx0) + *(nums + idx1) == target) {
                size_t s = 2 * sizeof(int);
                int *ret = malloc(s);
                memset(ret, '\0', s);
                *ret = idx0;
                *(ret + 1) = idx1;
                return ret;
            }
        }
    }
    return NULL;
}

int main(int argc, char *argv[]) {
    int nums[4] = {2, 7, 11, 15};
    size_t count = sizeof(nums) / sizeof(*nums);
    int target = 9;
    int *ret = twoSum(nums, count, target);
    if (ret) {
        for (int i = 0; i < 2; ++i) {
            printf("num's index: %d\n", *(ret + i));
        }
        free(ret);
        ret = NULL;
    }
    return EXIT_SUCCESS;
}
