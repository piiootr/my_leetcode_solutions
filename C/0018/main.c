/*
0018
https://leetcode.com/problems/valid-parentheses/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
    #define SUM4(A, B, C, D) (nums[A]+nums[B]+nums[C]+nums[D])
    int **solution;
    int a, b, c, d;
    int u, v, w, x;
    int t_sum;
    int t1, t2, t3, t4;
    int ARR_SIZE = 32;

    // sort array
    a = 0;
    while(a < (numsSize - 1)) {
        if(nums[a] > nums[a + 1]) {
            nums[a] ^= nums[a + 1];
            nums[a + 1] ^= nums[a];
            nums[a] ^= nums[a + 1];

            if(a > 0) a--;
            else a++;
        } else a++;
    }

    // solution magic
    solution = (int **) malloc(sizeof(int*) * ARR_SIZE);
    *returnSize = 0;
    a = 0;
    b = 1;
    c = numsSize - 2;
    d = numsSize - 1;
    while(a < b && b < c && c < d) {
        t_sum = SUM4(a, b, c, d);

        if(t_sum == target) {
            if(*returnSize >= ARR_SIZE) {
                    ARR_SIZE *= 2;
                    solution = (int **) realloc((void *)solution, (size_t)(ARR_SIZE) * sizeof(int*));
            }

            solution[*returnSize] = (int*) malloc(sizeof(int) * 4);
            solution[*returnSize][0] = nums[a];
            solution[*returnSize][1] = nums[b];
            solution[*returnSize][2] = nums[c];
            solution[*returnSize][3] = nums[d];

            (*returnSize)++;
        }

        if(a == (b - 1) && b == (c - 1) && c == (d - 1)) break;

        u = a;
        v = b;
        w = c;
        x = d;

        if(u < (b - 1)) {
            u++;
            while(u < (b - 1) && nums[u] == nums[u - 1]) u++;
        }
        if(v < (c - 1)) {
            v++;
            while(v < (c - 1) && nums[v] == nums[v - 1]) v++;
        }
        if(w > (b + 1)) {
            w--;
            while(w > (b + 1) && nums[w] == nums[w + 1]) w--;
        }
        if(x > (c + 1)) {
            x--;
            while(x > (c + 1) && nums[x] == nums[x + 1]) x--;
        }

        t1 = SUM4(u, b, c, d);
        t2 = SUM4(a, v, c, d);
        t3 = SUM4(a, b, w, d);
        t4 = SUM4(a, b, c, x);

        if(nums[u] == nums[a]) t1 = INT_MAX;
        if(nums[v] == nums[b]) t2 = INT_MAX;
        if(nums[w] == nums[c]) t3 = INT_MAX;
        if(nums[x] == nums[d]) t4 = INT_MAX;

        if(t_sum < target) {
            if(t1 == INT_MAX && t2 == INT_MAX) break;
            else if(t1 == INT_MAX && t2 != INT_MAX) b = v;
            else if(t1 != INT_MAX && t2 == INT_MAX) a = u;
            else if(abs(target - t1) < abs(target - t2)) a = u;
            else b = v;
        } else if(t_sum > target) {
            if(t3 == INT_MAX && t4 == INT_MAX) break;
            else if(t3 == INT_MAX && t4 != INT_MAX) d = x;
            else if(t3 != INT_MAX && t4 == INT_MAX) c = w;
            else if(abs(t3 - target) < abs(t4 - target)) c = w;
            else d = x;
        } else {
            if(t1 == INT_MAX && t2 == INT_MAX && t3 == INT_MAX && t4 == INT_MAX) break;
            if(t1 < t2 && t1 < t3 && t1 < t4) a = u;
            else if(t2 < t3 && t2 < t4) b = v;
            else if(t3 < t4) c = w;
            else d = x;
        }

    }

    *returnColumnSizes = malloc(*returnSize * sizeof(int));
    for(a = 0; a < *returnSize; a++) (*returnColumnSizes)[a] = 4;
    return solution;
}


int main(int argc, char** argv)
{
    int i, j;

    //int nums[] = {1,0,-1,0,-2,2};
    //int target = 0; // [[-2,-1,1,2], [-2,0,0,2], [-1,0,0,1]]
    //int nums[] = {2,2,2,2,2};
    //int target = 8; // [[2,2,2,2]]
    int nums[] = {-2,-1,-1,1,1,2,2};
    int target = 0; // [[-2,-1,1,2], [-1,-1,1,1]]

    int **sol;
    int returnSize;
    int *returnColumnSizes;
    int numsSize = (int)(sizeof(nums) / sizeof(nums[0]));

    sol = fourSum(nums, numsSize, target, &returnSize, &returnColumnSizes);

    for(i = 0; i < returnSize; i++) {
        printf("[");
        for(j = 0; j < returnColumnSizes[i]; j++) {
            printf("%2d,", sol[i][j]);
        }
        printf("]\n");
    }

    return 0;
}