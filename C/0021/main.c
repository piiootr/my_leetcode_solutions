/*
0021
https://leetcode.com/problems/merge-two-sorted-lists/
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

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    int i = 0;
    int j = 0;
    struct ListNode* t_node;
    struct ListNode* solution;

    if(list1 == NULL) return list2;
    if(list2 == NULL) return list1;

    if(list1->val < list2->val) {
        solution = t_node = list1;
        list1 = list1->next;
    }
    else {
        solution = t_node = list2;
        list2 = list2->next;
    }

    while(list1 || list2) {
        if(list2 == NULL) {
            t_node->next = list1;
            break;
        }
        if(list1 == NULL) {
            t_node->next = list2;
            break;
        }

        if(list1->val < list2->val) {
            t_node->next = list1;
            list1 = list1->next;
        } else {
            t_node->next = list2;
            list2 = list2->next;
        }

        t_node = t_node->next;
    }

    return solution;
}

int main(int argc, char** argv)
{
    return 0;
}