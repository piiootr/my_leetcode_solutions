/*
0136
https://leetcode.com/problems/single-number/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int singleNumber(int* nums, int numsSize) {
    bool check[60000] = {0};
    int solution = 0;
    int i;

    for(i = 0; i < numsSize; i++) {
        if(check[nums[i] + 30000] == 0) {
            check[nums[i] + 30000] = 1;
            solution += nums[i];
        }
        else {
            solution -= nums[i];
        }
    }

    return solution;

    /*
    int sum;
    int i;

    i = 0;
    while(i < (numsSize - 1)) {
        if(nums[i] > nums[i + 1]) {
            nums[i] ^= nums[i + 1];
            nums[i + 1] ^= nums[i];
            nums[i] ^= nums[i + 1];

            if(i < 1) i++;
            else i--;
        }
        else i++;
    }

    i = 0;
    while(i < (numsSize - 1)) {
        if(nums[i] == nums[i + 1]) {
            i += 2;
        }
        else break;
    }

    return nums[i];
    */
}

int main(int argc, char** argv)
{
    return 0;
}