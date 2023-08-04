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

bool check(TreeNode *leftTree, TreeNode *rightTree)
{
    if (leftTree == NULL || rightTree == NULL)
        return leftTree == rightTree;

    if (leftTree->val != rightTree->val)
        return false;

    bool LR = check(leftTree->left, rightTree->right);
    if (!LR)
        return false;
    bool RL = check(leftTree->right, rightTree->left);
    return RL;
}
bool isSymmetric(TreeNode *root)
{
    return check(root->left, root->right);
}

int main()
{

    return 0;
}