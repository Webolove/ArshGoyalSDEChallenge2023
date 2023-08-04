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

vector<int> rightSideView(TreeNode *root)
{
    if (root == NULL)
        return {};

    queue<TreeNode *> qu;
    qu.push(root);

    vector<int> ans;

    while (!qu.empty())
    {
        int size = qu.size();
        for (int i = 0; i < size; ++i)
        {
            TreeNode *front = qu.front();
            qu.pop();

            if (i == size - 1)
                ans.push_back(front->val);

            if (front->left)
                qu.push(front->left);
            if (front->right)
                qu.push(front->right);
        }
    }
    return ans;
}

int main()
{

    return 0;
}