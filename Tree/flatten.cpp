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

//                      Recursive Way
// TreeNode* prev = NULL;
// void flatten(TreeNode* root) {
//     if(root == NULL)
//         return;

//     flatten(root->right);
//     flatten(root->left);
//     root->right = prev;
//     root->left = NULL;
//     prev = root;
// }

//                      Morris Traversal
// void flatten(TreeNode* root){
//     TreeNode* curr = root;

//     while(curr != NULL){
//         if(curr->left != NULL){
//             TreeNode* temp = curr->left;
//             while(temp->right != NULL)
//                 temp = temp->right;

//             temp->right = curr->right;
//             curr->right = curr->left;
//             curr->left = NULL;
//             curr = curr->right;
//         }else{
//             curr = curr->right;
//         }
//     }
// }

//                  Iterative stack approach
void flatten(TreeNode *root)
{
    if (root == NULL)
        return;
    stack<TreeNode *> st;
    st.push(root);

    while (!st.empty())
    {
        TreeNode *top = st.top();
        st.pop();

        if (top->right)
            st.push(top->right);
        if (top->left)
            st.push(top->left);

        if (!st.empty())
            top->right = st.top();
        else
            top->right = NULL;
        top->left = NULL;
    }
}

int main()
{
    return 0;
}