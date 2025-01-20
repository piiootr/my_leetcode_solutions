/*
0006
https://leetcode.com/problems/zigzag-conversion/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows) {
    char *t;
    size_t i, r, c;

    if(strlen(s) < 2 || numRows < 2) return s;

    t = calloc(strlen(s) * numRows, 1);
    i = c = r = 0;
    while(i < strlen(s)) {
        t[strlen(s) * r + c] = s[i];

        if(i % (numRows * 2 -  2) < (numRows - 1)) r++;
        else {
            r--;
            c++;
        }
        i++;
    }

    i = c = 0;
    while(i < strlen(s)) {
        while(!t[c]) c++;
        s[i++] = t[c++];
    }

    free(t);
    return s;
}

int main(int argc, char** argv)
{
    char s[] = "A";
    int numRows = 1;

    printf("%s\n", convert(s, numRows));
    return 0;
}