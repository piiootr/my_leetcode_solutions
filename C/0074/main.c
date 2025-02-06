/*
0074
https://leetcode.com/problems/search-a-2d-matrix/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    int i, j;

    i = 0;
    while(i < matrixSize) {
        if(matrix[i][0] > target) break;
        i++;
    }
    if(i == 0) return false;

    i--;
    j = 0;
    while(j < matrixColSize[i]) {
        if(matrix[i][j] == target) return true;

        if(matrix[i][j] > target) return false;

        j++;
    }

    return false;
}

int main(int argc, char** argv)
{
    return 0;
}