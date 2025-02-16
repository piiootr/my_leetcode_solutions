/*
0326
https://leetcode.com/problems/power-of-three/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

bool isPowerOfThree(int n) {
    int x;

    if(n == 1) return true; /* smallest possible number */
    if(n % 3 != 0 || n < 3) return false;
    if(n > 1162261467) return false; /*.biggest possible number */

    x = 3;
    while(x < n) {
        x *= 3;
    }

    if(x == n) return true;
    return false;
}

int main(int argc, char** argv)
{
    return 0;
}