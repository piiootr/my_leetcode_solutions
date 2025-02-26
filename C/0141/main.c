/*
0141
https://leetcode.com/problems/linked-list-cycle/
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
}
;
bool hasCycle(struct ListNode *head) {
    int i;
    int s;
    struct ListNode* arr[10000];

    if(!head || head->next == NULL) return false;

    arr[0] = head;
    head = head->next;
    s = 1;

    if(head == arr[0]) return true;

    while(head->next) {
        for(i = 0; i < s; i++) {
            if(head == arr[i]) return true;
        }
        arr[s++] = head;
        head = head->next;
    }

    return false;
}

int main(int argc, char** argv)
{
    return 0;
}