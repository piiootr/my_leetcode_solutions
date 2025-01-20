/*
0004
https://leetcode.com/problems/median-of-two-sorted-arrays/
*/

#include <stdio.h>
#include <stdlib.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    double solution;
    double h;
    int i_median;
    int i1 = 0;
    int i2 = 0;

    if(nums1Size + nums2Size == 0) return 0.0;
    if(nums1Size == 0) {
        if(nums2Size & 1) return (double) nums2[nums2Size / 2];
        else  return ((double) nums2[nums2Size / 2 - 1] + (double) nums2[nums2Size / 2]) / 2.0;
    }
    if(nums2Size == 0) {
        if(nums1Size & 1) return (double) nums1[nums1Size / 2];
        else  return ((double) nums1[nums1Size / 2 - 1] + (double) nums1[nums1Size / 2]) / 2.0;
    }

    i_median = (nums1Size + nums2Size) / 2;
    while(i1 + i2 < i_median - 1) {
        if(i1 >= nums1Size) i2++;
        else if(i2 >= nums2Size) i1++;
        else nums1[i1] < nums2[i2] ? i1++ : i2++;
    }

    if((nums1Size + nums2Size) & 1) {
        if(i1 >= nums1Size) i2++;
        else if(i2 >= nums2Size) i1++;
        else nums1[i1] < nums2[i2] ? i1++ : i2++;

        if(i1 >= nums1Size) return (double) nums2[i2];
        else if(i2 >= nums2Size) return (double) nums1[i1];
        else return nums1[i1] < nums2[i2] ? (double) nums1[i1] : (double) nums2[i2];
    }
    else {
        if(i1 >= nums1Size) h = (double) nums2[i2++];
        else if(i2 >= nums2Size) h = (double) nums1[i1++];
        else h = nums1[i1] < nums2[i2] ? (double) nums1[i1++] : (double) nums2[i2++];

        if(i1 >= nums1Size) h = (h + (double) nums2[i2]) / 2.0;
        else if(i2 >= nums2Size) h = (h + (double) nums1[i1]) / 2.0;
        else h = nums1[i1] < nums2[i2] ? (h + (double) nums1[i1]) / 2.0 : (h + (double) nums2[i2]) / 2.0;
        return h;
    }

    return 0.0;
}

int main(int argc, char** argv)
{
    int a[] = {1, 2};
    int al = sizeof(a) / sizeof(*a);

    int b[] = {3, 4};
    int bl = sizeof(b) / sizeof(*b);

    printf("median: %f\n", findMedianSortedArrays(&a[0], al, &b[0], bl));

    return 0;
}


/*


1, 2    - 2
3, 4    - 2







*/