/*
https://leetcode.com/problems/zigzag-conversion/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows) {
}

int main(int argc, char** argv)
{
    char s[] = "PAYPALISHIRING";
    int numRows = 3;

    convert(s, numRows);
    printf("\n");
    return 0;
}


/*

ABCDEFGHIJKLMNO - 2

ACEGI % 2 == 0
BDFHJ % 2 == 1


ABCDEFGHIJKLMNO - 3

A   E   I  -> % 4 == 0
B D F H J  -> % 4 == 1 & 3
C   G   K  -> % 4 == 2


ABCDEFGHIJKLMNO - 4

A     G     M  -> % 6 = 0
B   F H   L    -> % 6 =
C E   I K      ->
D     J        ->


ABCDEFGHIJKLMNO - 5

A       I  -> % 8
B     H J  -> % 8
C   G   K  -> % 8
D F     L  -> % 8
E       M  -> % 8





 */