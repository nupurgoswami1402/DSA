#include <stdio.h>
#include <stdlib.h>

int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int* result = (int*)malloc(sizeof(int) * nums1Size);
    
    for (int i = 0; i < nums1Size; i++) {
        int found = 0;
        int next = -1;
        for (int j = 0; j < nums2Size; j++) {
            if (nums2[j] == nums1[i]) {
                found = 1;
                continue;
            }
            if (found && nums2[j] > nums1[i]) {
                next = nums2[j];
                break;
            }
        }
        result[i] = next;
    }
    
    *returnSize = nums1Size;
    return result;
}

/* Test
int main() {
    int nums1[] = {4,1,2};
    int nums2[] = {1,3,4,2};
    int returnSize;

    int* res = nextGreaterElement(nums1, 3, nums2, 4, &returnSize);

    for (int i = 0; i < returnSize; i++)
        printf("%d ", res[i]);
    printf("\n");

    free(res);
    return 0;
}
*/