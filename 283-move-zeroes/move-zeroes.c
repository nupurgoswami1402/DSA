#include <stdio.h>

void moveZeroes(int* nums, int numsSize){
    int lastNonZeroFoundAt = 0;

    // Step 1: Move all non-zero elements forward
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            nums[lastNonZeroFoundAt++] = nums[i];
        }
    }

    // Step 2: Fill remaining elements with 0
    for (int i = lastNonZeroFoundAt; i < numsSize; i++) {
        nums[i] = 0;
    }
}
