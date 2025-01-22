/*
0012
https://leetcode.com/problems/integer-to-roman/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

char* intToRoman(int num) {
    char *s;
    int c = 0;

    s = malloc(100);
    while(num > 0) {
        if(num >= 1000) {
            s[c++] = 'M';
            num -= 1000;
        }
        else if(num >= 900) {
            s[c++] = 'C';
            s[c++] = 'M';
            num -= 900;
        }
        else if(num >= 500) {
            s[c++] = 'D';
            num -= 500;
        }
        else if(num >= 400) {
            s[c++] = 'C';
            s[c++] = 'D';
            num -= 400;
        }
        else if(num >= 100) {
            s[c++] = 'C';
            num -= 100;
        }
        else if(num >= 90) {
            s[c++] = 'X';
            s[c++] = 'C';
            num -= 90;
        }
        else if(num >= 50) {
            s[c++] = 'L';
            num -= 50;
        }
        else if(num >= 40) {
            s[c++] = 'X';
            s[c++] = 'L';
            num -= 40;
        }
        else if(num >= 10) {
            s[c++] = 'X';
            num -= 10;
        }
        else if(num >= 9) {
            s[c++] = 'I';
            s[c++] = 'X';
            num -= 9;
        }
        else if(num >= 5) {
            s[c++] = 'V';
            num -= 5;
        }
        else if(num >= 4) {
            s[c++] = 'I';
            s[c++] = 'V';
            num -= 4;
        }
        else if(num >= 1) {
            s[c++] = 'I';
            num -= 1;
        }
    }
    s[c] = '\0';
    return s;
}


int main(int argc, char** argv)
{
    int a = 3749;
    printf("%d == %s\n", a, intToRoman(a));
    return 0;
}