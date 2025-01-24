/*
0020
https://leetcode.com/problems/valid-parentheses/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

bool isValid(char* s) {
    size_t i;
    int counters[6] = {0};
    char str;
    int c = 0;

    str = malloc(strlen(s));

    if(strlen(s) < 2) return false;

    for(i = 0; i < strlen(s); i++) {
        if(s[i] = '(' || str[i] == '')
        switch(s[i]) {
            case '(': str[c] = s[i]; break;
            case ')': counters[0]--; break;
            case '[': counters[1]++; break;
            case ']': counters[1]--; break;
            case '{': counters[2]++; break;
            case '}': counters[2]--; break;
        }
        if(counters[0] < 0 || counters[1] < 0 || counters[2] < 0) return false;
    }

    if(counters[0] == 0 && counters[1] == 0 && counters[2] == 0) return true;

    return true;
}


int main(int argc, char** argv)
{
    char s[] = "([)]";

    // "[(())]"

printf("%s\n", isValid(s) ? "true" : "false");
    return 0;
}