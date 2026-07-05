#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* values = (int*)malloc(numsSize * sizeof(int));
    int* indices = (int*)malloc(numsSize * sizeof(int));
    int count = 0;
    
    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        
        for (int j = 0; j < count; j++) {
            if (values[j] == complement) {
                int* result = (int*)malloc(2 * sizeof(int));
                result[0] = indices[j];
                result[1] = i;
                *returnSize = 2;
                
                free(values);
                free(indices);
                return result;
            }
        }
        
        values[count] = nums[i];
        indices[count] = i;
        count++;
    }
    
    free(values);
    free(indices);
    *returnSize = 0;
    return NULL;
}