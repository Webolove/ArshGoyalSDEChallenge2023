#include <iostream>
using namespace std;

struct Node
{
    int key;
    Node *left;
    Node *right;
    Node(int data)
    {
        key = data;
        left = NULL;
        right = NULL;
    }
};

void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
{
    // finding floor value or predecessor or first largest element which is smaller than key
    Node *temp = root;
    pre = NULL;
    while (temp != NULL)
    {
        if (temp->key >= key)
            temp = temp->left;
        else
        {
            pre = temp;
            temp = temp->right;
        }
    }

    // finding ceil value or successor or first smallest element which is larget than key
    temp = root;
    suc = NULL;
    while (temp != NULL)
    {
        if (temp->key <= key)
            temp = temp->right;
        else
        {
            suc = temp;
            temp = temp->left;
        }
    }
}

int main()
{
    return 0;
}