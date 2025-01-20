/*
0007
https://leetcode.com/problems/reverse-integer/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int reverse(int x){
    int solution;
    char *st;
    size_t i;
    char c;
    int h = 1;

    if(x == INT_MIN || x == 0) return 0;

    /* 12 is the max number of digits from INT_MIN + minus sign + NULL termination*/
    st = calloc(12, 1);
    if(x < 0) {
        h = -1;
        x = -x;
    }

    sprintf(st, "%d", x);
    for(i = 0; i < strlen(st) / 2; i++) {
        c = st[strlen(st) - 1 - i];
        st[strlen(st) - 1 - i] = st[i];
        st[i] = c;
    }
    if(strlen(st) == 10){
        i = 0;
        while(i < 10) {
            if(st[i] > "2147483647"[i]) return 0;
            else if(st[i] < "2147483647"[i]) break;
            i++;
        }
    }

    solution = h * (int) strtol(st, NULL, 10);
    free(st);
    return solution;
}

int main(int argc, char** argv)
{
    int x = -2147483412;

    printf("MAX: %d\n", INT_MAX);
    printf("MIN: %d\n", INT_MIN);
    printf("x: %d\n", x);
    printf("s: %d\n", reverse(x));
    return 0;
}