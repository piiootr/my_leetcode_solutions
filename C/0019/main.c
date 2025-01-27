/*
0019
https://leetcode.com/problems/remove-nth-node-from-end-of-list/
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

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    int i;
    struct ListNode* all_nodes[30] = {0};
    int n_nodes;
    int target;

    if(head == NULL) return head;
    if(head->next == NULL && n == 1) return NULL;
    if(head->next == NULL) return head;

    i = 0;
    all_nodes[i] = head;
    for(i = 1; all_nodes[i - 1]->next; i++) {
        all_nodes[i] = all_nodes[i - 1]->next;
    }

    n_nodes = i;
    target = i - n;

    if(target == 0) return all_nodes[1];

    all_nodes[target - 1]->next = all_nodes[target]->next;
    return head;
}


int main(int argc, char** argv)
{
    return 0;
}