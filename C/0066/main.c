/*
0066
https://leetcode.com/problems/plus-one/
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
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int* solution;
    int i, h;

    if(digits[0] == 9) solution = (int*) malloc(sizeof(int) * (size_t)(digitsSize + 1));
    else solution = (int*) malloc(sizeof(int) * (size_t)digitsSize);

    h = 1;
    for(i = (digitsSize - 1); i > -1; i--) {

        solution[i] = (digits[i] + h) % 10;

        h = (digits[i] + h ) / 10;
    }

    if(h == 1) {
        for(i = 0; i < digitsSize; i++) {
            solution[digitsSize - i] = solution[digitsSize - 1 - i];
        }

        solution[0] = 1;
    }

    if(solution[0] == 1 && digits[0] == 9) {
        *returnSize = digitsSize + 1;
    } else {
        *returnSize = digitsSize;
        solution = realloc(solution, sizeof(int) * (size_t)digitsSize);
    }

    return solution;
}

int main(int argc, char** argv)
{
    return 0;
}