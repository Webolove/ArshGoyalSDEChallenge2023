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

int solve(TreeNode *root, int &maxi)
{
    if (root == NULL)
        return 0;

    int lD = solve(root->left, maxi);
    int rD = solve(root->right, maxi);

    maxi = max(maxi, 1 + lD + rD);
    return 1 + max(lD, rD);
}
int diameterOfBinaryTree(TreeNode *root)
{
    int maxi = 0;
    solve(root, maxi);
    return maxi - 1;
}

int main()
{

    return 0;
}