/*
0263
https://leetcode.com/problems/ugly-number/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

bool isUgly(int n) {
    if(n < 1) return false;

    while(n % 5 == 0) n /= 5;
    while(n % 3 == 0) n /= 3;
    while(n % 2 == 0) n /= 2;

    if(n == 1) return true;
    return false;
}

int main(int argc, char** argv)
{
    return 0;
}