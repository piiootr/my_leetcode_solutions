/*
0088
https://leetcode.com/problems/merge-sorted-array/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int i, j;

    i = m;
    j = 0;
    while((i + j) < nums1Size) {
        nums1[i + j] = nums2[j];
        j++;
    }

    i = 0;
    while(i < (nums1Size - 1)) {
        if(nums1[i] > nums1[i + 1]) {
            nums1[i] ^= nums1[i + 1];
            nums1[i + 1] ^= nums1[i];
            nums1[i] ^= nums1[i + 1];

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