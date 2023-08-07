#include "bits/stdc++.h"
using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;
    Node(int data)
    {
        val = data;
        left = NULL;
        right = NULL;
    }
};

Node *bToDLL(Node *root)
{
    Node *head = NULL;
    Node *prev = NULL;

    stack<Node *> st;
    st.push(root);

    Node *curr = root;
    while (!st.empty())
    {
        if (curr != NULL)
        {
            if (curr->left != NULL)
                st.push(curr->left);
            curr = curr->left;
        }
        else
        {
            Node *node = st.top();
            st.pop();

            if (head == NULL) // It will be executed only once🙃
                head = node;

            curr = node->right;

            if (node->right != NULL)
                st.push(node->right);

            node->left = prev;
            if (prev != NULL)
                prev->right = node;
            prev = node;
        }
    }
    prev->right = NULL;

    return head;
}

int main()
{
    return 0;
}