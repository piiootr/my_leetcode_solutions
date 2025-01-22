/*
0013
https://leetcode.com/problems/roman-to-integer/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int romanToInt(char* s) {
    int c = 0;
    int n = 0;

    while(s[c]) {
        if(s[c] == 'C' && s[c+1] == 'M') {
            n += 900;
            c += 2;
        }
        else if(s[c] == 'C' && s[c+1] == 'D') {
            n += 400;
            c += 2;
        }
        else if(s[c] == 'X' && s[c+1] == 'C') {
            n += 90;
            c += 2;
        }
        else if(s[c] == 'X' && s[c+1] == 'L') {
            n += 40;
            c += 2;
        }
        else if(s[c] == 'I' && s[c+1] == 'X') {
            n += 9;
            c += 2;
        }
        else if(s[c] == 'I' && s[c+1] == 'V') {
            n += 4;
            c += 2;
        }
        else {
            switch(s[c]) {
                case 'M': n += 1000; c++; break;
                case 'D': n += 500; c++; break;
                case 'C': n += 100; c++; break;
                case 'L': n += 50; c++; break;
                case 'X': n += 10; c++; break;
                case 'V': n += 5; c++; break;
                case 'I': n += 1; c++; break;
            }
        }
    }
    return n;
}


int main(int argc, char** argv)
{
    char s[] = "MMMDCCXLIX";
    printf("%s == %d\n", s, romanToInt(s));
    return 0;
}