/*
0033
https://leetcode.com/problems/search-in-rotated-sorted-array/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int search(int* nums, int numsSize, int target) {
    int i;

    i = 0;
    while(i < (numsSize / 2)) {
        if(nums[i] == target) return i;
        if(nums[numsSize - 1 - i] == target) return (numsSize - 1 - i);

        i++;
    }

    if(nums[i] == target) return i;
    return -1;
}

int main(int argc, char** argv)
{
    return 0;
}