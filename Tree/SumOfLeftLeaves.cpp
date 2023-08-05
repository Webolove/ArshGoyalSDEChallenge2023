#include <iostream>
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

int solve(TreeNode *root, int direction)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL && direction == -1)
        return root->val;

    return solve(root->left, -1) + solve(root->right, 1);
}

int sumOfLeftLeaves(TreeNode *root)
{
    return solve(root, 0);
}

int main()
{
    return 0;
}