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

vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    if (root == NULL)
        return {};
    vector<vector<int>> ans;
    queue<TreeNode *> qu;
    qu.push(root);

    bool flag = true;
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

        if (flag)
            ans.push_back(temp);
        else
        {
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
        }
        flag = !flag;
    }
    return ans;
}

int main()
{
    return 0;
}