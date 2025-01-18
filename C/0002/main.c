#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* solution;
    struct ListNode* h;

    h = malloc(sizeof(struct ListNode));
    h->val = 0;
    h->next =  NULL;
    solution = h;

    while(l1 || l2) {
        if(l1) h->val += l1->val;
        if(l2) h->val += l2->val;

        if((l1 && l1->next) || (l2 && l2->next) || h->val >= 10) {
            h->next = malloc(sizeof(struct ListNode));
            h->next->val = h->val / 10;
            h->val %= 10;
            h = h->next;
        }

        if(l1) l1 = l1->next;
        if(l2) l2 = l2->next;
    }
    h->next = NULL;

    return solution;
}


int main(int argc, char** argv)
{
    struct ListNode a3 = {.val = 2, .next =  NULL};
    struct ListNode a2 = {.val = 3, .next = &a3};
    struct ListNode a1 = {.val = 8, .next = &a2};
    //struct ListNode a1 = {.val = 5, .next = NULL};

    struct ListNode b3 = {.val = 1, .next = NULL};
    struct ListNode b2 = {.val = 2, .next = &b3};
    struct ListNode b1 = {.val = 9, .next = &b2};
    //struct ListNode b1 = {.val = 5, .next = NULL};

    struct ListNode* c = addTwoNumbers(&a1, &b1);

    while(c->next) {
        printf("%d", c->val);
        c = c->next;
    }
    printf("%d\n", c->val);

    return 0;
}
