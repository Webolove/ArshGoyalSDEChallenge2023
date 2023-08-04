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

TreeNode *buildTree(int left, int right, vector<int> &nums)
{
    if (left > right)
        return NULL;

    int mid = (right - left) / 2 + left;
    TreeNode *root = new TreeNode(nums[mid]);
    root->left = buildTree(left, mid - 1, nums);
    root->right = buildTree(mid + 1, right, nums);
    return root;
}
TreeNode *sortedArrayToBST(vector<int> &nums)
{
    return buildTree(0, nums.size() - 1, nums);
}

int main()
{

    return 0;
}