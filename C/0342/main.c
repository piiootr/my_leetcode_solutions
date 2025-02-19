/*
0342
https://leetcode.com/problems/power-of-four/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

bool isPowerOfFour(int n) {
    int x = 1;

    if(n < 1) return false;
    while(x < n && x < (INT_MAX / 4)) {
        x = x << 2;
    }

    if(x == n) return true;
    return false;
}

int main(int argc, char** argv)
{
    return 0;
}