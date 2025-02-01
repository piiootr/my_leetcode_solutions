/*
0035
https://leetcode.com/problems/search-insert-position/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int searchInsert(int* nums, int numsSize, int target) {
    int solution;
    int i;

    i = 0;
    while(i < numsSize) {
        solution = i;

        if(nums[i] >= target) break;

        i++;
    }

    if(i == numsSize && nums[i - 1] < target) return i;

    return solution;
}

int main(int argc, char** argv)
{
    return 0;
}