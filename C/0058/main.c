/*
0058
https://leetcode.com/problems/length-of-last-word/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int lengthOfLastWord(char* s) {
    int i, j;
    int solution;

    i = (int) strlen(s);

    j = 0;
    while(j < (i - 1) && s[i - 1 - j] == ' ') j++;

    solution = 0;
    while(solution != (i - j) && s[i - 1 - j - solution] != ' ') solution++;

    return solution;
}

int main(int argc, char** argv)
{
    return 0;
}