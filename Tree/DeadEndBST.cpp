#include <iostream>
#include <climits>
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

bool solve(Node *root, int lower_limit, int upper_limit)
{
    if (root == NULL)
        return false;
    if (root->left == NULL && root->right == NULL)
    {
        if (max(0, lower_limit) + 1 == root->data && root->data + 1 == upper_limit)
            return true;
        return false;
    }

    bool left = solve(root->left, lower_limit, root->data);
    if (left)
        return true;
    bool right = solve(root->right, root->data, upper_limit);

    return right;
}
bool isDeadEnd(Node *root)
{
    return solve(root, 0, INT_MAX);
}

int main()
{
    return 0;
}