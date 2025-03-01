/*
0905
https://leetcode.com/problems/sort-array-by-parity/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParity(int* nums, int numsSize, int* returnSize) {
    int i = 0;

    while(i < (numsSize - 1)) {
        if((nums[i] & 1) && !(nums[i + 1] & 1)) {
            nums[i] ^= nums[i + 1];
            nums[i + 1] ^= nums[i];
            nums[i] ^= nums[i + 1];

            if(i < 1) i++;
            else i--;
        } else i++;
    }

    *returnSize = numsSize;
    return nums;
}

int main(int argc, char** argv)
{
    return 0;
}