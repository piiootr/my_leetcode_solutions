/*
0100
https://leetcode.com/problems/same-tree/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    bool result = true;

    if(!p && !q) return true;
    if(!p || !q) return false;

    if(p->val != q->val) return false;

    if(p->left && !(q->left)) return false;
    if(!(p->left) && q->left) return false;

    if(p->right && !(q->right)) return false;
    if(!(p->right) && q->right) return false;


    if(p->left && q->left) result = isSameTree(p->left, q->left);
    if(!result) return false;
    if(p->right && q->right) result = isSameTree(p->right, q->right);
    return result;
}

int main(int argc, char** argv)
{
    return 0;
}