/*
0014
https://leetcode.com/problems/longest-common-prefix/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    int i;
    int h = 0;

    if(strsSize == 1) return strs[0];

    while(strs[0][h]) {
        for(i = 1; i < strsSize; i++) {
            if(strs[0][h] != strs[i][h]) {
                strs[0][h] = '\0';
                return strs[0];
            }
        }
        h++;
    }

    return strs[0];
}

int main(int argc, char** argv)
{
    char str1[] = "flower";
    char str2[] = "flow";
    char str3[] = "flight";
    char **str = malloc(3 * sizeof(char *));
    str[0] = str1;
    str[1] = str2;
    str[2] = str3;

    printf("pref: %s\n", longestCommonPrefix(str, 3));

    free(str);
    return 0;
}