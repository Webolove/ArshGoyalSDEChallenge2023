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

int NoOfCameras = 0;
string solve(TreeNode *root)
{
    if (root == NULL)
        return "ok";

    string left = solve(root->left);
    string right = solve(root->right);

    if (left == "want" || right == "want")
    {
        NoOfCameras++;
        return "provide";
    }
    else if (left == "provide" || right == "provide")
        return "ok";
    return "want";
}
int minCameraCover(TreeNode *root)
{
    if (solve(root) == "want")
        NoOfCameras++;
    return NoOfCameras;
}

int main()
{

    return 0;
}