/*
0026
https://leetcode.com/problems/remove-duplicates-from-sorted-array/
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

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    struct ListNode** nodes;
    struct ListNode* t_node;
    struct ListNode* end;
    struct ListNode* solution;
    int i;

    if(head == NULL || head->next == NULL) return head;

    nodes = (struct ListNode**) malloc(sizeof(struct ListNode) * k);
    solution = NULL;

    while(1) {

        nodes[k-1] = NULL;
        for(i = 0; i < k && head; i++) {
            nodes[i] = head;
            head = head->next;
        }
        if(nodes[k-1] == NULL) {
            break;
        }

        for(i = 0; i < k / 2; i++) {
            t_node = nodes[i];
            nodes[i] = nodes[k - 1 - i];
            nodes[k - 1 - i] = t_node;
        }

        for(i = 0; i < (k - 1); i++){
            nodes[i]->next = nodes[i+1];
        }

        if(solution == NULL) {
            solution = nodes[0];
        }
        else {
            end->next = nodes[0];
        }
        end = nodes[k - 1];
        end->next = head;
    }

    free(nodes);
    return solution;
}


int main(int argc, char** argv)
{
    return 0;
}