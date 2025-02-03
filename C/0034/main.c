/*
0034
https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
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
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int* solution;
    int i, j;

    solution = (int*) malloc(sizeof(int) * 2);
    solution[0] = solution[1] = -1;

    i = 0;
    j = numsSize - 1;
    while(i < numsSize && i <= j && (solution[0] == - 1 || solution[1] == - 1)) {

        if(nums[i] == target) {
            solution[0] = i;
        }
        if(nums[j] == target) {
            solution[1] = j;
        }

        if(solution[0] == -1) i++;
        if(solution[1] == -1) j--;
    }

    *returnSize = 2;
    return solution;
}

int main(int argc, char** argv)
{
    return 0;
}