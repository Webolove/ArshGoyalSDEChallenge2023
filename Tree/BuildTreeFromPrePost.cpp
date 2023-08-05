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

TreeNode *buildTree(int preStart, int preEnd, vector<int> preOrder,
                    int postStart, int postEnd, vector<int> postOrder)
{
    if (preStart > preEnd || postStart > postEnd)
        return NULL;
    if (preStart == preEnd || postStart == postEnd)
    {
        TreeNode *root = new TreeNode(preOrder[preStart]);
        return root;
    }
    TreeNode *root = new TreeNode(preOrder[preStart]);

    // finding the range of left and right subtree
    int nextRoot = preOrder[preStart + 1];
    int i = postStart;
    for (i = postStart; i < postEnd; i++)
    {
        if (postOrder[i] == nextRoot)
            break;
    }
    int Total_left_Nodes = i - postStart + 1;

    // New Ranges for left Branch;
    int left_preStart = preStart + 1;
    int left_preEnd = preStart + Total_left_Nodes;
    int left_postStart = postStart;
    int left_postEnd = i;
    root->left = buildTree(left_preStart, left_preEnd, preOrder, left_postStart, left_postEnd, postOrder);

    // New Ranges for right Branch;
    int right_preStart = left_preEnd + 1;
    int right_preEnd = preEnd;
    int right_postStart = i + 1;
    int right_postEnd = postEnd - 1;
    root->right = buildTree(right_preStart, right_preEnd, preOrder, right_postStart, right_postEnd, postOrder);

    return root;
}
TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder)
{
    return buildTree(0, preorder.size() - 1, preorder, 0, postorder.size() - 1, postorder);
}

int main()
{
    return 0;
}