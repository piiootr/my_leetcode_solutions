/*
0222
https://leetcode.com/problems/count-complete-tree-nodes/
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

int countNodes(struct TreeNode* root) {
    int result = 0;

    if(!root) return result;

    result++;
    if(root->left) result += countNodes(root->left);
    if(root->right) result += countNodes(root->right);

    return result;
}


int main(int argc, char** argv)
{
    return 0;
}