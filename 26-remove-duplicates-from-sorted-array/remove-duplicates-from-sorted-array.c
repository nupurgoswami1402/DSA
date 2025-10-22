#include <stdio.h>

int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0) return 0;

    int i = 0; // position for next unique element
    for (int j = 1; j < numsSize; j++) {
        if (nums[j] != nums[i]) {
            i++;
            nums[i] = nums[j];
        }
    }
    return i + 1; // new length
}

/* Test the function
int main() {
    int nums[] = {0,0,1,1,1,2,2,3,3,4};
    int numsSize = sizeof(nums)/sizeof(nums[0]);

    int newLength = removeDuplicates(nums, numsSize);

    printf("New length: %d\n", newLength);
    printf("Array after removing duplicates: ");
    for (int i = 0; i < newLength; i++)
        printf("%d ", nums[i]);
    printf("\n");

    return 0;
}*/
