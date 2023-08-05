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

int maxDepth(TreeNode *root)
{
    if (root == NULL)
        return 0;

    queue<TreeNode *> qu;
    qu.push(root);
    int level = 0;
    while (!qu.empty())
    {
        int size = qu.size();
        level++;
        for (int i = 0; i < size; ++i)
        {
            TreeNode *front = qu.front();
            qu.pop();

            if (front->left)
                qu.push(front->left);
            if (front->right)
                qu.push(front->right);
        }
    }
    return level;
}

int main()
{

    return 0;
}