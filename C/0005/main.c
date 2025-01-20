/*
0005
https://leetcode.com/problems/longest-palindromic-substring/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestPalindrome(char* s) {
    char* solution;
    size_t i;
    size_t offset;
    size_t l_substr;
    size_t l_str = strlen(s);

    if(!s) return NULL;
    if(l_str < 2) return s;

    for(l_substr = l_str; l_substr > 0; l_substr--) {
        for(offset = 0; offset <= l_str - l_substr; offset++) {
            for(i = 0; i < l_substr / 2; i++) {
                if(s[offset + i] != s[l_substr + offset - 1 - i]) break;
                if(i == l_substr / 2 - 1) {
                    printf("off: %lu - l_substr: %lu\n", offset, l_substr);
                    s = &(s[offset]);
                    if(strlen(s) >= l_substr) s[l_substr] = '\0';
                    return s;
                }
            }
        }
    }
    s[1] = '\0';
    return s;
}

int main(int argc, char** argv)
{
    //char s[] = "qwertzuioasdfghjnn";
    //char s[] = "babad";
    //char s[] = "abba";
    char s[] = "ab";

    printf("origin: %s; substr: %s\n", s, longestPalindrome(s));

    return 0;
}
