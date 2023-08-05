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

bool hasPathSum(TreeNode *root, int targetSum)
{
    if (root == NULL)
        return false;
    if (targetSum - root->val == 0 && root->left == NULL && root->right == NULL)
        return true;

    bool checkLeft = hasPathSum(root->left, targetSum - root->val);
    if (checkLeft)
        return true;
    bool checkRight = hasPathSum(root->right, targetSum - root->val);
    return checkRight;
}

int main()
{
    return 0;
}