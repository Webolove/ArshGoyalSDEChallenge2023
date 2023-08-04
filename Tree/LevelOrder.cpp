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

vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
        return ans;

    queue<TreeNode *> qu;
    qu.push(root);
    while (!qu.empty())
    {
        int size = qu.size();

        vector<int> temp;
        for (int i = 0; i < size; ++i)
        {
            TreeNode *front = qu.front();
            qu.pop();

            temp.push_back(front->val);
            if (front->left)
                qu.push(front->left);
            if (front->right)
                qu.push(front->right);
        }

        ans.push_back(temp);
    }
    return ans;
}

int main()
{

    return 0;
}