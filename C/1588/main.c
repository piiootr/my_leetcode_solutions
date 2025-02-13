/*
1588
https://leetcode.com/problems/sum-of-all-odd-length-subarrays/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int sumOddLengthSubarrays(int* arr, int arrSize) {
    int i, j, k;
    int sum;

    sum = 0;

    for(i = 0; i < arrSize; i++) {
        for(j = 1; j <= arrSize; j += 2) {
            if((i + j) > arrSize) break;

            for(k = 0; k < j; k++) {
                if((i + k) >= arrSize) break;
                sum += arr[i + k];
            }
        }
    }

    return sum;
}

int main(int argc, char** argv)
{
    return 0;
}