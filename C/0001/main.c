/*
0001
https://leetcode.com/problems/two-sum/
*/

#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int i, j;
    int* solution = malloc(2 * sizeof(int));

    if(numsSize == 2) {
        solution[0] = 0;
        solution[1] = 1;
        *returnSize = 2;
        return solution;
    }

    for(i = 0; i < numsSize - 1; i++) {
        for(j = i + 1; j < numsSize; j++) {
            if(nums[i] + nums[j] == target) {
                solution[0] = i;
                solution[1] = j;
                *returnSize = 2;
                return solution;
            }
        }
    }
    return NULL;
}

int main(int argc, char** argv) {

    int nums[] = {2,7,11,15};
    int numsSize = 4;
    int target = 22;
    int targetSize;

    int *solution = twoSum(&nums[0], numsSize, target, &targetSize);

    if(solution){
        printf("a: %d; b: %d\n", solution[0], solution[1]);
        free(solution);
    }
    return 0;
}