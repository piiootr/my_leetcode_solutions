/*
0118
https://leetcode.com/problems/pascals-triangle/
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
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    int** result;
    int i, j, k;

    *returnSize = numRows;
    result = (int**)malloc(sizeof(int*) * (*returnSize));
    *returnColumnSizes = (int*)malloc(sizeof(int) * numRows);

    result[0] = (int*)malloc(sizeof(int) * 1);
    result[0][0] = 1;
    (*returnColumnSizes)[0] = 1;

    for(i = 1; i < numRows; i++) {
        result[i] = (int*)malloc(sizeof(int) * (i + 1));

        (*returnColumnSizes)[i] = i + 1;

        for(j = 0; j < ((i / 2) + 1); j++) {
            result[i][j] =
                j == 0 ?
                    1 : result[i - 1][j - 1] + result[i - 1][j];
            result[i][i - j] =
                j == 0 ?
                    1 : result[i - 1][i - j] + result[i - 1][i - j - 1];
        }
    }

    return result;
}

int main(int argc, char** argv)
{
    return 0;
}