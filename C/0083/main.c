/*
0083
https://leetcode.com/problems/remove-duplicates-from-sorted-list/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

/*
 * Definition for singly-linked list.
*/
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* t;
    struct ListNode* result = head;

    while(head && head->next) {
        t = head->next;

        while(t && head->val == t->val) t = t->next;

        head->next = t;
        head = head->next;
    }

    return result;
}

int main(int argc, char** argv)
{
    return 0;
}