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

int kthSmallest(TreeNode *root, int k)
{
    stack<TreeNode *> st;
    st.push(root);
    TreeNode *curr = root;
    int ans = 0;

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
            TreeNode *top = st.top();
            st.pop();

            k -= 1;
            if (k == 0)
            {
                ans = top->val;
                break;
            }

            if (top->right != NULL)
                st.push(top->right);
            curr = top->right;
        }
    }

    return ans;
}

int main()
{
    return 0;
}