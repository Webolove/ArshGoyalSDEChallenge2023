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

bool isValidBST_I(TreeNode *root)
{
    vector<int> BST;

    stack<TreeNode *> st;
    st.push(root);

    TreeNode *curr = root;

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
            TreeNode *temp = st.top();
            st.pop();
            BST.push_back(temp->val);
            if (temp->right != NULL)
                st.push(temp->right);
            curr = temp->right;
        }
    }

    //                              MORRIS TRAVERSAL
    // TreeNode* curr = root;
    // while(curr != NULL)
    // {
    //     if(curr->left == NULL)
    //     {
    //         BST.push_back(curr->val);
    //         curr = curr->right;
    //     }
    //     else{
    //         TreeNode* temp = curr->left;
    //         while(temp->right != NULL && temp->right != curr)
    //             temp = temp->right;
    //         if(temp->right == NULL)
    //         {
    //             temp->right = curr;
    //             curr = curr->left;
    //         }
    //         else{
    //             BST.push_back(curr->val);
    //             temp->right = NULL;
    //             curr = curr->right;
    //         }
    //     }
    // }

    for (int i = 1; i < BST.size(); ++i)
    {
        if (BST[i] <= BST[i - 1])
            return false;
    }
    return true;
}

// ONe more way is to mark a range for every node
bool check(TreeNode *root, long long low, long long high)
{
    if (root == NULL)
        return true;

    if (!(root->val > low && root->val < high))
        return false;

    bool checkLeft = check(root->left, low, root->val);
    bool checkRight = check(root->right, root->val, high);
    return checkLeft & checkRight;
}
bool isValidBST_II(TreeNode *root)
{

    long long low = -1e15;
    long long high = 1e15;
    return check(root, low, high);
}

int main()
{

    return 0;
}