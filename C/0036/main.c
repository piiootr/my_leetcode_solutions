/*
0036
https://leetcode.com/problems/valid-sudoku/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    int ix, iy;
    int x, y;
    int n;

    for(iy = 0; iy < 9; iy++) {
        for(ix = 0; ix < 9; ix++) {
            if(board[iy][ix] == '.') continue;

            // check row and column for duplicates
            for(n = 0; n < 9; n++) {
                // check row
                if(n != ix && board[iy][n] != '.' && board[iy][n] == board[iy][ix]) return false;

                // check column
                if(n != iy && board[n][ix] != '.' && board[n][ix] == board[iy][ix]) return false;
            }

            // check 3x3 field for duplicates
            for(y = (iy / 3) * 3; y < (((iy / 3) * 3) + 3); y++) {
                for(x = (ix / 3) * 3; x < (((ix / 3) * 3) + 3); x++) {
                    if(y == iy && x == ix) continue;

                    if(board[y][x] == board[iy][ix]) return false;
                }
            }

        }
    }

    return true;
}

int main(int argc, char** argv)
{
    return 0;
}