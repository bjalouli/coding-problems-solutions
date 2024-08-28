#include <stdio.h>
#include <stdlib.h>

int* two_sum(int* nums, int numsSize, int target) {
    int* result = (int*)malloc(2 * sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }
    free(result);
    return NULL;
}

int main() {
    int nums[] = {2,3,4,5,6,7,8,9,10};
    int target = 10;
    int returnSize;
    
    int* indices = two_sum(nums, sizeof(nums) / sizeof(nums[0]), target);

    if (indices) {
        printf("Indices: [%d, %d]\n", indices[0], indices[1]);
        free(indices);
    } else {
        printf("No solution found.\n");
    }

    return 0;
}
