/*
0003
https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lengthOfLongestSubstring(char* s) {
    int i = 0;
    int j = 0;
    int solution = 0;
    char chars[256] = {0};

    while(*(s + i + j)) {
        if (chars[(int)*(s+i+j)] == 0) {
            chars[(int)*(s+i+j)] = 1;
            j++;
        } else {
            if(j > solution) solution = j;
            memset(&chars[0], 0, 256);
            j = 0;
            i++;
        }
    }
    if(j > solution) solution = j;
    return solution;
}

int main(int argc, char** argv)
{
    char *s = "a";
    printf("lenght: %d\n", lengthOfLongestSubstring(s));
    return 0;
}
