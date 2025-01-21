/*
0009
https://leetcode.com/problems/palindrome-number/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

bool isPalindrome(int x) {
    char *s;
    int i;
    int l_s;

    if(x < 0) return false;
    if(x < 10) return true;

    s = calloc(11, 1);
    sprintf(s, "%d", x);
    l_s = strlen(s);

    for(i = 0; i < l_s / 2; i++) {
        if(s[i] != s[l_s - 1 - i]) {
            free(s);
            return false;
        }
    }
    return true;
}

int main(int argc, char** argv)
{
    int x = 10;
    printf("x: %d -> %s\n", x, isPalindrome(x) ? "true" : "false");
    return 0;
}