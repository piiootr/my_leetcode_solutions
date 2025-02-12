/*
0029
https://leetcode.com/problems/divide-two-integers/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int divide(int dividend, int divisor) {
    int result;
    unsigned int d1, d2;
    int s1, s2;

    if(divisor == 1) return dividend;
    if(dividend == INT_MIN && divisor == -1) return INT_MAX;

    if(dividend < 0) {
        s1 = -1;
        if(dividend == INT_MIN) d1 = (unsigned int)INT_MAX + 1u;
        else d1 = (unsigned int)(-dividend);
    }
    else {
        s1 = 1;
        d1 = (unsigned int)dividend;
    }

    if(divisor < 0) {
        s2 = -1;
        if(divisor == INT_MIN) d2 = (unsigned int)INT_MAX + 1u;
        else d2 = (unsigned int)(-divisor);
    }
    else {
        s2 = 1;
        d2 = (unsigned int)divisor;
    }

    if(d2 > d1) return 0;

    result = (int) (d1 / d2);

    return s1 * s2 * result;
}

int main(int argc, char** argv)
{
    return 0;
}