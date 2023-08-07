#include "bits/stdc++.h"
using namespace std;

// Given the root of a binary tree, calculate the vertical order traversal of the binary tree.
// For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).
// The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.
// Return the vertical order traversal of the binary tree.

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

vector<vector<int>> verticalTraversal(TreeNode *root)
{
    map<int, map<int, multiset<int>>> mp;
    queue<pair<TreeNode *, int>> qu; // {Node, col}
    qu.push({root, 0});
    int level = 0;

    while (!qu.empty())
    {
        int size = qu.size();
        for (int i = 0; i < size; ++i)
        {
            TreeNode *Node = qu.front().first;
            int col = qu.front().second;
            qu.pop();

            mp[col][level].insert(Node->val);

            if (Node->left)
                qu.push({Node->left, col - 1});
            if (Node->right)
                qu.push({Node->right, col + 1});
        }
        level++;
    }

    vector<vector<int>> ans;
    for (auto col : mp)
    {
        vector<int> temp;
        for (auto level : col.second)
        {
            for (auto node : level.second)
                temp.push_back(node);
        }
        ans.push_back(temp);
    }
    return ans;
}

int main()
{
    return 0;
}