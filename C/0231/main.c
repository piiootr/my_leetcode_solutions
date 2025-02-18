/*
0231
https://leetcode.com/problems/power-of-two/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

bool isPowerOfTwo(int n) {
    int x = 1;

    if(n < 1) return false;
    if(n > ((-1) * (INT_MIN / 2))) return false;

    while(x < n) {
        x = x << 1;
    }

    if(x == n) return true;
    return false;
}

int main(int argc, char** argv)
{
    return 0;
}