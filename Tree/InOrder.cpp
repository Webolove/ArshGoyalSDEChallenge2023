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

vector<int> ans;
// Way 1 : Recursive
void inOrder(TreeNode *root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    ans.push_back(root->val);
    inOrder(root->right);
}
vector<int> inorderTraversal(TreeNode *root)
{
    if (root == NULL)
        return {};
    // Way 1 :
    // inOrder(root);

    // Way 2 : Stack
    // stack<TreeNode*> st;
    // st.push(root);

    // TreeNode* curr = root;
    // while(!st.empty()){
    //     if(curr != NULL){
    //         if(curr->left != NULL)
    //             st.push(curr->left);
    //         curr = curr->left;
    //     }else{
    //         TreeNode* Top = st.top();
    //         st.pop();

    //         ans.push_back(Top->val);

    //         if(Top->right != NULL)
    //             st.push(Top->right);
    //         curr = Top->right;
    //     }
    // }

    // Way 3 : Morris Traversal
    TreeNode *curr = root;
    while (curr != NULL)
    {
        if (curr->left != NULL)
        {
            TreeNode *temp = curr->left;
            while (temp->right != NULL && temp->right != curr)
                temp = temp->right;
            if (temp->right == NULL)
            {
                temp->right = curr;
                curr = curr->left;
            }
            else
            {
                ans.push_back(curr->val);
                curr = curr->right;
                temp->right = NULL;
            }
        }
        else
        {
            ans.push_back(curr->val);
            curr = curr->right;
        }
    }

    return ans;
}

int main()
{
    return 0;
}