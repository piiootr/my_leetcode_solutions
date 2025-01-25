/*
0017
https://leetcode.com/problems/letter-combinations-of-a-phone-number/
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
char** letterCombinations(char* digits, int* returnSize) {
    size_t l_str = strlen(digits);
    int i, j, k;
    char **solution;
    int *counter;
    char c, d;

    if(l_str < 1) {
        *returnSize = 0;
        return NULL;
    }

    *returnSize = 1;
    for(i = 0; i < l_str; i++) {
        if(digits[i] == '7' || digits[i] == '9') *returnSize *= 4;
        else *returnSize *= 3;
    }

    counter = (int*) malloc(sizeof(int) * l_str);
    for(i = 0; i < l_str; i++) counter[i] = 0;

    solution = (char**) malloc(sizeof(char*) * *returnSize);
    for(i = 0; i < *returnSize; i++) {
        solution[i] = (char*) calloc(l_str + 1 , 1);

        for(j = 0; j < l_str; j++) {
            d = digits[j];

            if(d < '7') {
                c = (char)((int)'a' + (3 * (int)(digits[j] - '2')) + counter[j]);
            } else if(d == '7') {
                c = (char)((int)'p' + counter[j]);
            } else if(d == '8') {
                c = (char)((int)'t' + counter[j]);
            } else {
                c = (char)((int)'w' + counter[j]);
            }

            solution[i][j] = c;

            if(j == (l_str - 1)) { counter[j]++; }

            k = 0;
            while(
                j - k >= 1 &&
                (((digits[j - k] == '7' || digits[j - k] == '9') && counter[j - k] == 4) ||
                ((digits[j - k] < '7' || digits[j - k] == '8') && counter[j - k] == 3))
            ) {
                if(digits[j - k] == '7' || digits[j - k] == '9') counter[j - k] %= 4;
                else counter[j - k] %= 3;

                counter[j - k - 1]++;
                k++;
            }
        }
    }

    free(counter);
    return solution;
}

int main(int argc, char** argv)
{
    int i;
    char str[] = "23";
    char **solution;

    int l_solution;
    solution = letterCombinations(str, & l_solution);
    for(i = 0; i < l_solution; i++) {
        printf("(%d) %s\n", i+1, solution[i]);
    }


    return 0;
}