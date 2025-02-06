/*
0061
https://leetcode.com/problems/rotate-list/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* rotateRight(struct ListNode* head, int k) {
    struct ListNode* solution;
    struct ListNode* t;
    int n;
    int i;


    if(k == 0 || head == NULL || head->next == NULL) return head;

    n = 1;
    t = head;
    while(t->next) {
        t = t->next;
        n++;
    }
    k = k % n;
    if(k == 0) return head;

    t->next = head;
    t = head;
    i = 0;
    while(i < ((n - k) - 1)) {
        t = t->next;
        i++;
    }

    solution = t->next;
    t->next = NULL;

    return solution;
}

int main(int argc, char** argv)
{
    return 0;
}