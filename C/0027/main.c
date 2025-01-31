/*
0027
https://leetcode.com/problems/remove-element/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>


int removeElement(int* nums, int numsSize, int val) {
    int i, j;

    i = j = 0;

    while(j < numsSize) {

        while(j < numsSize && nums[j] == val) j++;

        if(j >= numsSize) break;

        nums[i] = nums[j++];

        i++;
    }

    return i;
}


int main(int argc, char** argv)
{
    return 0;
}