/*
0028
https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>


int strStr(char* haystack, char* needle) {
    size_t l1;
    size_t l2;
    int i, j;

    if(!haystack || !needle) return -1;

    l1 = strlen(haystack);
    l2 = strlen(needle);

    if(l2 > l1) return -1;

    i = j = 0;

    while(j <= (l1 - l2)) {

        if(needle[i] == haystack[i + j]) {
            while(needle[i] && needle[i] == haystack[i + j]) i++;

            if(i == (int) l2) return j;

            i = 0;
            j++;
        }

        else j++;

    }

    return -1;
}


int main(int argc, char** argv)
{
    return 0;
}