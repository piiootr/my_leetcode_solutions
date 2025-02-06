/*
0055
https://leetcode.com/problems/jump-game/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

bool canJump(int* nums, int numsSize) {
    int i, j;

    if(numsSize == 1) return true;

    j = 1;
    for(i = (numsSize - 2); i > 0; i--) {
        if(nums[i] >= j) j = 1;
        else j++;
    }

    if(nums[i] < j) return false;
    return true;
}

int main(int argc, char** argv)
{
    return 0;
}