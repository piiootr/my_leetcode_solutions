/*
0069
https://leetcode.com/problems/sqrtx/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int mySqrt(int x) {
    #define MAX_VALUE (46340) /* (int) sqrt(INT_MAX) */
    int i;

    i = 0;
    while((i * i) < x && i < MAX_VALUE) i++;

    if((i * i) == x) return i;
    if((i * i) < x) return (i);

    return (i - 1);
}

int main(int argc, char** argv)
{
    return 0;
}