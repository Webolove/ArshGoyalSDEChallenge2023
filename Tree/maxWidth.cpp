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

int widthOfBinaryTree(TreeNode *root)
{
    queue<pair<TreeNode *, long long int>> qu; // second value of pair represents index
    qu.push({root, 0});
    long long int ans = 1;
    while (!qu.empty())
    {
        long long int idx = qu.front().second;
        long long int first, last;
        int size = qu.size();

        for (int i = 0; i < size; ++i)
        {
            TreeNode *node = qu.front().first;
            long long int curr_id = qu.front().second - idx;
            qu.pop();

            if (i == 0)
                first = curr_id;
            if (i == size - 1)
                last = curr_id;
            if (node->left != NULL)
                qu.push({node->left, curr_id * 2 + 1});
            if (node->right != NULL)
                qu.push({node->right, curr_id * 2 + 2});
        }
        ans = max(ans, last - first + 1);
    }
    return ans;
}

int main()
{
    return 0;
}