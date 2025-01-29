/*
0024
https://leetcode.com/problems/swap-nodes-in-pairs/
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

struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode* a;
    struct ListNode* b;
    struct ListNode* c;
    struct ListNode* t_node;
    struct ListNode* solution;


    if(!head || !head->next) return head;

    a = head;
    b = head->next;
    c = head->next->next;

    b->next = a;
    a->next = c;

    solution = b;
    t_node = a;
    head = c;


    while(head && head->next) {
        a = head;
        b = head->next;
        c = head->next->next;

        b->next = a;
        a->next = c;

        t_node->next = b;
        t_node = a;
        head = c;
    }

    return solution;
}


int main(int argc, char** argv)
{
    return 0;
}