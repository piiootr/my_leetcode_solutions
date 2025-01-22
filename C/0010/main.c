/*
0010
https://leetcode.com/problems/regular-expression-matching/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

bool isMatch(char* s, char* p) {

    if(*s == *p && !s[1] && !p[1]) return true;
    if(*p == '.' && !s[1] && !p[1]) return true;
    if(*p == '.' && p[1] == '*' && !p[2]) return true;

    size_t i, j;
    size_t ls, lp;

    ls = strlen(s);
    lp = strlen(p);

/*
    s = "aaabb";
    p = "a*ac*a*.abb*k*."; -> true

    s = "aaababb";
    p = "a*ac*a*.abb*k*."; -> true
*/

    return true;
}


int main(int argc, char** argv)
{
    //char s[] = "ab";
    //char p[] = ".*"; // -> true
    //char s[] = "aab";
    //char p[] = "c*a*b"; // -> true
    char s[] = "mississippi";
    char p[] = "mis*is*p*."; // -> false
    //char s[] = "mississippi";
    //char p[] = "mis*is*ip*."; // -> true
    //char s[] = "aaba";
    //char p[] = "ab*a*c*a"; // -> false

    /*

    s = "aabbbs"
    p = "a*.*aab*." // -> true

    s = "aaaaaaabb"
    p = ".*aab*b." // -> true

    s = "aaaaaaabb";
    p = ".*aab*b"; // -> false

    s = "aaabb";
    p = "a*ac*a*.abb*k*."; -> true

    s = "aaababb";
    p = "a*ac*a*.abb*k*."; -> true
    */

    printf("s: %s\n", s);
    printf("p: %s\n", p);
    printf("solution: %s\n", isMatch(s, p) ? "true" : "false");
    return 0;
}