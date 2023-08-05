#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

int getCount(Node *root, int l, int h)
{
    if (root == NULL)
        return 0;

    int count = 0;

    if (root->data >= l && root->data <= h)
        count = 1 + getCount(root->left, l, h) + getCount(root->right, l, h);
    else if (root->data < l)
        count = getCount(root->right, l, h);
    else if (root->data > h)
        count = getCount(root->left, l, h);
    return count;
}

int main()
{
    return 0;
}