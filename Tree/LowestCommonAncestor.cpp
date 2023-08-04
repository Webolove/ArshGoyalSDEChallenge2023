#include "bits/stdc++.h"
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data)
    {
        val = data;
        left = NULL;
        right = NULL;
    }
};

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == NULL)
        return NULL;
    if (root->val == p->val || root->val == q->val)
        return root;

    TreeNode *goLeft = lowestCommonAncestor(root->left, p, q);
    TreeNode *goRight = lowestCommonAncestor(root->right, p, q);

    if (goLeft == NULL && goRight == NULL)
        return NULL;
    if (goLeft != NULL && goRight != NULL)
        return root;
    if (goLeft == NULL)
        return goRight;
    return goLeft;
}

int main()
{

    return 0;
}