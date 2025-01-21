/*
0008
https://leetcode.com/problems/string-to-integer-atoi/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

int myAtoi(char* s) {
    int i = 0;
    int l_str = (int) strlen(s);
    long solution = 0l;

    if(!s) return 0;

    while(i < l_str) {
        if(s[i] == ' ') i++;
        else if(s[i] == '+' || s[i] == '-') break;
        else if(s[i] >= '0' || s[i] <= '9') break;
        else return 0;
    }

    solution = strtol(&(s[i]), NULL, 10);
    if(solution < INT_MIN) solution = INT_MIN;
    if(solution > INT_MAX) solution = INT_MAX;
    return (int) solution;
}

int main(int argc, char** argv)
{
    char s[] = " b11228552307";
    //char s[] = " 42";
    printf("d: %d\n", myAtoi(s));
    printf("s: %s\n", s);
    return 0;
}