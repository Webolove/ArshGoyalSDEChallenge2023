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

vector<TreeNode *> buildTree(int left, int right)
{
    if (left > right)
        return {NULL};

    vector<TreeNode *> ans;
    for (int node = left; node <= right; ++node)
    {
        TreeNode *root = new TreeNode(node);

        vector<TreeNode *> leftSubtree = buildTree(left, node - 1);
        vector<TreeNode *> rightSubtree = buildTree(node + 1, right);

        for (auto l : leftSubtree)
        {
            for (auto r : rightSubtree)
            {
                TreeNode *root = new TreeNode(node);
                root->left = l;
                root->right = r;
                ans.push_back(root);
            }
        }
    }
    return ans;
}
vector<TreeNode *> generateTrees(int n)
{
    vector<TreeNode *> res = buildTree(1, n);
    return res;
}

int main()
{
    return 0;
}