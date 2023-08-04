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

vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
{
    unordered_map<TreeNode *, TreeNode *> parent; // {a, b} ---> b is parent of a;
    parent[root] = NULL;

    // Setting parent of Nodes;
    queue<TreeNode *> qu;
    qu.push(root);
    while (!qu.empty())
    {
        TreeNode *front = qu.front();
        qu.pop();

        if (front->left != NULL)
        {
            parent[front->left] = front;
            qu.push(front->left);
        }

        if (front->right != NULL)
        {
            parent[front->right] = front;
            qu.push(front->right);
        }
    }

    unordered_map<TreeNode *, bool> vis;
    qu.push(target);
    vis[target] = true;

    vector<int> ans;
    while (!qu.empty())
    {
        int size = qu.size();
        for (int i = 0; i < size; ++i)
        {
            TreeNode *front = qu.front();
            qu.pop();
            if (k == 0)
            {
                ans.push_back(front->val);
                continue;
            }

            if (front->left != NULL && vis[front->left] == false)
            {
                vis[front->left] = true;
                qu.push(front->left);
            }
            if (front->right != NULL && vis[front->right] == false)
            {
                vis[front->right] = true;
                qu.push(front->right);
            }
            if (parent[front] != NULL && vis[parent[front]] == false)
            {
                vis[parent[front]] = true;
                qu.push(parent[front]);
            }
        }
        k--;
        if (k < 0)
            break;
    }
    return ans;
}

int main()
{

    return 0;
}