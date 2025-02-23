/*
0204
https://leetcode.com/problems/count-primes/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int countPrimes(int n) {
    int result;
    bool* arr;
    int i, j;

    if(n < 3) return 0;

    arr = (bool*) calloc(n, sizeof(bool));

    result = 0;
    i = 2;
    while(i < n) {
        result++;

        j = i;
        while(j < n) {
            arr[j] = true;
            j += i;
        }

        while(i < n && arr[i] == true) i++;
    }

    free(arr);
    return result;
}

int main(int argc, char** argv)
{
    return 0;
}