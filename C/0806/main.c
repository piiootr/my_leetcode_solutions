/*
0806
https://leetcode.com/problems/number-of-lines-to-write-string/
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
int* numberOfLines(int* widths, int widthsSize, char * s, int* returnSize){
    int* result;
    int i;
    int w;

    result = (int*)malloc(sizeof(int) * 2lu);
    result[0] = 1;
    result[1] = 0;

    while(s[i]) {
        w = widths[s[i] - 'a'];

        if(result[1] + w <= 100) {
            result[1] += w;
        }
        else {
            result[1] = w;
            result[0] += 1;
        }

        i++;
    }

    *returnSize = 2;
    return result;
}

int main(int argc, char** argv)
{
    int nums[] = {10,10,3,7,6};
    int numsSize = (int)(sizeof(nums) / sizeof(nums[0]));

    printf("s: %d\n", countPartitions(nums, numsSize));

    return 0;
}