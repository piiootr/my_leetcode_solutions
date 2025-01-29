/*
0023
https://leetcode.com/problems/merge-k-sorted-lists/
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

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    struct ListNode* t_node;
    struct ListNode* solution;
    int i_best;
    int val_best;
    int i;

    i_best = -1;
    val_best = INT_MAX;
    for(i = 0; i < listsSize; i++) {
        if(lists[i] && lists[i]-> val < val_best) {
            val_best = lists[i]->val;
            i_best = i;
        }
    }
    if(i_best < 0) return NULL;

    solution = t_node = lists[i_best];
    lists[i_best] = lists[i_best]->next;

    while(true)
    {
        val_best = INT_MAX;
        i_best = -1;

        for(i = 0; i < listsSize; i++) {
            if(!lists[i]) continue;

            if(lists[i]->val < val_best) {
                val_best = lists[i]->val;
                i_best = i;
            }
        }

        if(i_best > -1) {
            t_node->next = lists[i_best];
            lists[i_best] = lists[i_best]->next;
            t_node = t_node->next;
        }
        else break;
    }

    return solution;
}


int main(int argc, char** argv)
{
    return 0;
}