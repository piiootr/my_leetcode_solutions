/*
0016
https://leetcode.com/problems/3sum-closest/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int threeSumClosest(int* nums, int numsSize, int target) {
    #define THREE_SUM(A, B, C) (nums[A] + nums[B] + nums[C])
    #define DIFF_TARGET(A) (abs(target - A))
    #define A_SMALLER_DIFF_B(A, B) (DIFF_TARGET(A) <= DIFF_TARGET(B))

    int i = 0, j = 1, k = numsSize - 1;
    int s;
    int h = 0;
    int a, b, c;
    int x, y, z;

    while(h < numsSize - 1) {
        if(nums[h] > nums[h + 1]) {
            nums[h] ^= nums[h + 1];
            nums[h + 1] ^= nums[h];
            nums[h] ^= nums[h + 1];

            if(h > 0) h--;
            else h++;
        } else h++;
    }

    printf("sorted:\n");
    printf("[");
    for(h = 0; h < numsSize; h++) printf("%3d,", nums[h]);
    printf("]\n");

    s = THREE_SUM(i, j, k);
    while(i < j && j < k) {
        printf("sorted:\n");
        printf("[");
        for(h = 0; h < numsSize; h++) printf("%3d,", nums[h]);
        printf("]\n");
        printf("(%2d, %2d, %2d) - [%3d, %3d, %3d]\n", i, j, k, nums[i], nums[j], nums[k]);
        h = THREE_SUM(i, j, k);
        if(A_SMALLER_DIFF_B(h, s)) {
            s = h;
        }

        if((i + 1) < j && (j + 1) < k) {
            printf("1\n");
            x = i + 1;
            y = j + 1;
            z = k - 1;
            while(x < j && nums[x] == nums[x + 1]) x++;
            while(y < k && nums[y] == nums[y + 1]) y++;
            while(z > j && nums[z] == nums[z - 1]) z--;
            a = THREE_SUM(x, j, k);
            b = THREE_SUM(i, y, k);
            c = THREE_SUM(i, j, z);

            if(A_SMALLER_DIFF_B(a, b) && A_SMALLER_DIFF_B(a, c)) {
                printf("1.1\n");
                i = x;
            } else if(A_SMALLER_DIFF_B(b, c)) {
                printf("1.2\n");
                j = y;
            } else {
                printf("1.3\n");
                k = z;
            }
        } else if((j + 1) < k) {
            printf("2\n");
            y = j + 1;
            z = k - 1;
            while(y < k && nums[y] == nums[y + 1]) y++;
            while(z > j && nums[z] == nums[z - 1]) z--;
            b = THREE_SUM(i, y, k);
            c = THREE_SUM(i, j, z);

            if(A_SMALLER_DIFF_B(b, c)) {
                printf("2.1\n");
                j = y;
            } else {
                printf("2.2\n");
                k = z;
            }
        } else {
            i++;
            while(i < j && nums[i] == nums[i + 1]) i++;
        }
        if(i+1 == j && j+1 == k) break;
    }

    return s;
    #undef THREE_SUM
}


int main(int argc, char** argv)
{
    //int arr[] = {4,0,5,-5,3,3,0,-4,-5};
    int arr[] = {-1,2,1,-4};
    //int arr[] = {1,1,1,0};
    //int arr[] = {-4,2,2,3,3,3};
    //int arr[] = {2,2,3,3,3, 0, 0, 1, 0, 1};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    int t = 0;

    printf("t: %2d || s: %2d\n", t, threeSumClosest(&arr[0], arr_size, t));

    return 0;
}