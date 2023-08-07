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

string serialize(TreeNode *root)
{
    string str = "";
    if (root == NULL)
        return "N";

    queue<TreeNode *> qu;
    str += to_string(root->val);
    str += "#";
    qu.push(root);

    while (!qu.empty())
    {
        int size = qu.size();

        for (int i = 0; i < size; ++i)
        {
            TreeNode *front = qu.front();
            qu.pop();

            if (front->left)
            {
                qu.push(front->left);
                str += to_string(front->left->val);
                str += "#";
            }
            else
                str += "N";

            if (front->right)
            {
                qu.push(front->right);
                str += to_string(front->right->val);
                str += "#";
            }
            else
                str += "N";
        }
    }
    return str;
}

// Decodes your encoded data to tree.

int findNum(string data, int &idx)
{
    string num = "";
    while (data[idx] != '#')
    {
        num += data[idx];
        idx++;
    }

    return stoi(num);
}

TreeNode *deserialize(string data)
{
    if (data == "N")
        return NULL;

    int idx = 0;
    int num = findNum(data, idx);
    TreeNode *root = new TreeNode(num);
    idx++;

    queue<TreeNode *> qu;
    qu.push(root);

    while (!qu.empty())
    {
        int size = qu.size();

        for (int i = 0; i < size; ++i)
        {
            if (data[idx] != 'N')
            {
                num = findNum(data, idx);
                TreeNode *temp = new TreeNode(num);

                qu.front()->left = temp;
                qu.push(temp);
            }
            idx++;

            if (data[idx] != 'N')
            {
                num = findNum(data, idx);
                TreeNode *temp = new TreeNode(num);

                qu.front()->right = temp;
                qu.push(temp);
            }
            idx++;
            qu.pop();
        }
    }
    return root;
}

int main()
{
    return 0;
}