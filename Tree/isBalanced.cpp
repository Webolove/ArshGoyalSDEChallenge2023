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

int check(TreeNode *root)
{
    if (root == NULL)
        return 0;

    int left = check(root->left);
    if (left < 0)
        return -1e8;
    int right = check(root->right);

    if (abs(left - right) >= 2)
        return -1e8;

    return 1 + max(left, right);
}
bool isBalanced(TreeNode *root)
{
    return (check(root) >= 0);
}

int main()
{
    return 0;
}