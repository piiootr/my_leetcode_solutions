/*
0067
https://leetcode.com/problems/add-binary/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

char* addBinary(char* a, char* b) {
    char* solution;
    size_t la, lb, lmax;
    int i, h;
    int na, nb, n;

    la = strlen(a);
    lb = strlen(b);
    lmax = la > lb ? la : lb;

    solution = calloc((lmax + 2lu), 1);

    i = h = 0;
    while(i < lmax) {
        na = nb = 0;
        if(i < la) {
            na = (int)(a[la - 1 - i] - '0');
        }
        if(i < lb) {
            nb = (int)(b[lb - 1 - i] - '0');
        }

        n = (na + nb + h) % 2;
        h = (na + nb + h) / 2;

        solution[lmax - i] = (char)(n) + '0';
        i++;
    }

    if(h) solution[0] = (char)h + '0';
    else {
        for(i = 0; i < lmax; i++) {
            solution[i] = solution[i + 1];
        }
        solution[lmax] = '\0';
    }

    return solution;
}

int main(int argc, char** argv)
{
    return 0;
}