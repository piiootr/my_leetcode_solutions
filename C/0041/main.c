/*
0041
https://leetcode.com/problems/first-missing-positive/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int firstMissingPositive(int* nums, int numsSize) {
    int* arr = calloc(sizeof(int), numsSize);
    int i;

    for(i = 0; i < numsSize; i++) {
        if(nums[i] > 0 && nums[i] <= numsSize) {
            arr[nums[i] - 1] = 1;
        }
    }

    for(i = 0; i < numsSize; i++) {
        if(arr[i] != 1) return (i + 1);
    }

    free(arr);
    return (numsSize + 1);
}

int main(int argc, char** argv)
{
    return 0;
}