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

int rangeSumBST(TreeNode *root, int low, int high)
{
    if (root == NULL)
        return 0;

    if (root->val >= low && root->val <= high)
        return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);

    else if (root->val > high)
        return rangeSumBST(root->left, low, high);
    else if (root->val < low)
        return rangeSumBST(root->right, low, high);
    return 0;
}

int main()
{

    return 0;
}