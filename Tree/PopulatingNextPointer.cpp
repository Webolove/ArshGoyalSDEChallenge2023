#include "bits/stdc++.h"
using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;
    Node *next;
    Node(int data)
    {
        val = data;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};

Node *connect(Node *root)
{
    if (root == NULL)
        return root;

    queue<Node *> qu;
    qu.push(root);

    while (!qu.empty())
    {
        int size = qu.size();

        Node *prev = NULL;
        for (int i = 0; i < size; ++i)
        {
            Node *front = qu.front();
            qu.pop();

            if (prev != NULL)
                prev->next = front;
            prev = front;

            if (front->left)
                qu.push(front->left);
            if (front->right)
                qu.push(front->right);
        }
    }
    return root;
}

int main()
{
    return 0;
}