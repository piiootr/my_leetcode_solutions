/*
0075
https://leetcode.com/problems/sort-colors/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

void sortColors(int* nums, int numsSize) {
    int i = 0;

    while(i < numsSize - 1) {
        if(nums[i] > nums[i + 1]) {
            nums[i] ^= nums[i + 1];
            nums[i + 1] ^= nums[i];
            nums[i] ^= nums[i + 1];

            if(i < 1) i++;
            else i--;
        }
        else i++;
    }
}

int main(int argc, char** argv)
{
    return 0;
}