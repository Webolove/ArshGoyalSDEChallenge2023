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

vector<TreeNode *> nodes;
void findNode(TreeNode *root, int data)
{
    if (root == NULL)
        return;
    if (root->val == data)
        nodes.push_back(root);

    findNode(root->left, data);
    findNode(root->right, data);
}

bool check(TreeNode *temp, TreeNode *subRoot)
{
    if (temp == NULL || subRoot == NULL)
        return temp == subRoot;

    if (temp->val != subRoot->val)
        return false;
    return check(temp->left, subRoot->left) && check(temp->right, subRoot->right);
}
bool isSubtree(TreeNode *root, TreeNode *subRoot)
{
    findNode(root, subRoot->val);
    for (int i = 0; i < nodes.size(); ++i)
    {
        if (check(nodes[i], subRoot))
            return true;
    }
    return false;
}

int main()
{

    return 0;
}