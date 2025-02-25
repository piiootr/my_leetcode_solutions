/*
0206
https://leetcode.com/problems/reverse-linked-list/
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

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* arr[5000];
    struct ListNode* result;
    int i = 0;

    if(!head || head->next == NULL) return head;

    while(head) {
        arr[5000 - 1 - i] = head;

        head = head->next;

        i++;
    }

    arr[4999]->next = NULL;
    result = arr[5000 - i];

    for(i = i; i > 1; i--) {
        arr[5000 - i]->next = arr[5000 - i + 1];
    }

    return result;
}

int main(int argc, char** argv)
{
    return 0;
}