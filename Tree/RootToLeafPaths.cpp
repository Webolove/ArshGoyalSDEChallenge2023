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

void solve(TreeNode *root, string str, vector<string> &res)
{
    if (root == NULL)
        return;
    str += to_string(root->val);
    if (!(root->left == NULL && root->right == NULL))
        str += "->";
    else
    {
        res.push_back(str);
        return;
    }
    solve(root->left, str, res);
    solve(root->right, str, res);
}
vector<string> binaryTreePaths(TreeNode *root)
{
    vector<string> res;
    string str = "";
    solve(root, str, res);
    return res;
}

int main()
{

    return 0;
}