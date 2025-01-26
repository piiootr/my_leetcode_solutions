/*
3432
https://leetcode.com/problems/count-partitions-with-even-sum-difference/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int countPartitions(int* nums, int numsSize) {
    int i, j;
    int sum_l, sum_r;
    int solution = 0;

    for(i = 0; i < numsSize - 1; i++) {
        sum_l = sum_r = 0;
        for(j = 0; j < numsSize; j++) {
            if(j <= i) sum_l += nums[j];
            else sum_r += nums[j];
        }
        if(!((sum_l - sum_r) & 1)) solution++;
    }

    return solution;
}


int main(int argc, char** argv)
{
    int nums[] = {10,10,3,7,6};
    int numsSize = (int)(sizeof(nums) / sizeof(nums[0]));

    printf("s: %d\n", countPartitions(nums, numsSize));

    return 0;
}