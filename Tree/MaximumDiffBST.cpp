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

int getMinimumDifference(TreeNode *root)
{
    stack<TreeNode *> st;
    st.push(root);
    TreeNode *curr = root;

    int prev = -1e9;
    int ans = INT_MAX;

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
            ans = min(ans, top->val - prev);

            prev = top->val;
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