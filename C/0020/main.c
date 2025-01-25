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
    char *str;
    int c = 0;

    str = malloc(strlen(s));

    if(strlen(s) < 2) return false;

    for(i = 0; i < strlen(s); i++) {
        printf("i: %lu - s: %c - c: %d\n", i, s[i], c);
        if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
            str[c++] = s[i];
        } else {
            if(c == 0) return false;
            if(s[i] == ')') {
                if(str[c - 1] == '(') c--;
                else return false;
            } else if(s[i] == ']') {
                if(str[c - 1] == '[') c--;
                else return false;
            } else {
                if(str[c - 1] == '{') c--;
                else return false;
            }
        }
    }

    return false;
}


int main(int argc, char** argv)
{
    //char s[] = "([)]";
    //char s[] = "()";
    //char s[] = "()[]{}";
    char s[] = "(((";

printf("%s\n", isValid(s) ? "true" : "false");
    return 0;
}