/*
0121
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int maxProfit(int* prices, int pricesSize) {
    int solution;
    int i, j;
    int h1, h2;
    int t;

    i = 0;
    while(i < (pricesSize - 1) && prices[i] >= prices[i + 1]) i++;

    j = pricesSize - 1;
    while(j > 1 && prices[j] <= prices[j - 1]) j--;

    if(i >= j) return 0;

    h1 = prices[i];
    h2 = prices[j];
    solution = 0;
    while(i < (pricesSize - 1)) {

        while(i < (pricesSize - 2) && h1 < prices[i]) i++;
        h1 = prices[i];

        t = j;
        while(t > i) {

            while(t > (i + 1) && h2 > prices[t]) t--;
            h2 = prices[t];

            if(prices[t] - prices[i] > solution) solution = prices[t] - prices[i];

            t--;
        }

        i++;
    }

    return solution;
}


int main(int argc, char** argv)
{
    return 0;
}