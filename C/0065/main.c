/*
0065
https://leetcode.com/problems/valid-number/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

bool isNumber(char* s) {
    #define STATUS_COUNTER (len_status[0] + len_status[1] + len_status[2])
    int len_s;
    int status; /*0: digits before dot; 1: digits after dot; 2: digits after exponent*/
    int len_status[3];
    int i;

    len_s = strlen(s);
    if(len_s == 1 && (*s < '0' || *s > '9')) return false;

    status = 0;
    len_status[0] = len_status[1] = len_status[2] = 0;
    while(STATUS_COUNTER < len_s) {

        if(s[STATUS_COUNTER] >= 'A' && s[STATUS_COUNTER] <= 'Z' && s[STATUS_COUNTER] != 'E') return false;
        else if(s[STATUS_COUNTER] >= 'a' && s[STATUS_COUNTER] <= 'z' && s[STATUS_COUNTER] != 'e') return false;


        else if(s[STATUS_COUNTER] == '.') {
            if(status != 0) return false;
            if(len_status[1] > 0) return false;

            status = 1;
        }

        else if(s[STATUS_COUNTER] == 'E' || s[STATUS_COUNTER] == 'e') {
            if(status == 2) return false;
            if(len_status[0] == 0 && len_status[1] < 2) return false;

            status = 2;
        }

        else if(s[STATUS_COUNTER] == '+' || s[STATUS_COUNTER] == '-') {
            if(status == 1) return false;
            if(status == 0 && len_status[0] != 0) return false;
            if(status == 2 && len_status[2] != 1) return false;
        }

        len_status[status] += 1;
    }

    i = 0;
    while(i < (len_status[0] + len_status[1])) {
        if(s[i] >= '0' && s[i] <= '9') break;
        i++;
    }
    if(i >= (len_status[0] + len_status[1])) return false;

    if(len_status[2] == 1) return false;
    if(status == 2 && (s[STATUS_COUNTER - 1] < '0' || s[STATUS_COUNTER - 1] > '9')) return false;


    return true;
}

int main(int argc, char** argv)
{
    return 0;
}