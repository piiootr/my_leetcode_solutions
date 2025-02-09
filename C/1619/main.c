/*
1619
https://leetcode.com/problems/mean-of-array-after-removing-some-elements/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

double trimMean(int* arr, int arrSize) {
    int i;
    int sum;
    int i_start;
    int i_end;

    i = 0;
    while(i < (arrSize - 1)) {
        if(arr[i] < arr[i + 1]) {
            arr[i] ^= arr[i + 1];
            arr[i + 1] ^= arr[i];
            arr[i] ^= arr[i + 1];

            if(i > 0) i--;
            else i++;
        }
        else i++;
    }

    sum = 0;
    i_start = (int)((double)arrSize * 0.05);
    i_end = (int)((double)arrSize * 0.95);

    for(i = i_start; i < i_end; i++) {
        sum += arr[i];
    }

    return (double)sum / ((double)arrSize * 0.9);
}

int main(int argc, char** argv)
{
    return 0;
}