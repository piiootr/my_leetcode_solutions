/*
0085
https://leetcode.com/problems/maximal-rectangle/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize) {
    #define MIN(a, b) ((a) < (b) ? (a) : (b))
    #define MAX(a, b) ((a) > (b) ? (a) : (b))
    int result;
    int nx, ny;
    int x, y;
    int i, j;
    int h;
    int* cols;

    ny = matrixSize;
    nx = matrixColSize[0];

    cols = (int*) malloc(sizeof(int) * (size_t)nx);
    for(i = 0; i < nx; i++) cols[i] = 0;

    result = 0;
    for(y = 0; y < ny; y++) {
        for(x = 0; x < nx; x++) {
            if(matrix[y][x] == '0') cols[x] = 0;
            else cols[x] += 1;
        }

        h = 0;
        i = 0;
        while(i < nx) {
            j = 1;
            if(cols[i] > 0) {
                if(cols[i] > result) result = cols[i];
                h = cols[i];

                while((i + j) < nx && (cols[i + j] > 0)) {
                    h = MIN(h, cols[i + j]);
                    result = MAX(result, h * (j + 1));

                    j++;
                }
            }

            i++;
        }
    }

    return result;
}

int main(int argc, char** argv)
{
    return 0;
}