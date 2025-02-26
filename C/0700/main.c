/*
0700
https://leetcode.com/problems/search-in-a-binary-search-tree/
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

struct TreeNode* searchBST(struct TreeNode* root, int val) {
    struct TreeNode* result =  NULL;

    if(!root || root->val == val) return root;

    if(root->left) result = searchBST(root->left, val);
    if(result) return result;
    if(root->right) result = searchBST(root->right, val);

    return result;
}

int main(int argc, char** argv)
{
    return 0;
}