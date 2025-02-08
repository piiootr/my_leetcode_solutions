/*
0070
https://leetcode.com/problems/climbing-stairs/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int climbStairs(int n) {
    int solution;
    int h1, h2;
    int i;

    if(n == 1) return 1;
    if(n == 2) return 2;

    h1 = 1;
    h2 = 2;

    i = 2;
    while(i < n) {
        solution = h1 + h2;

        h1 = h2;
        h2 = solution;

        i++;
    }

    return solution;
}

/*

1: 1
2: 1+1; 2
3: 1+1+1; 2+1; 1+2;
4: 1+1+1+1; 2+1+1; 1+2+1; 1+1+2; 2+2;
5: 1+1+1+1+1; 2+1+1+1; 1+2+1+1; 1+1+2+1; 1+1+1+2; 2+2+1; 2+1+2; 1+2+2

*/

int main(int argc, char** argv)
{
    return 0;
}