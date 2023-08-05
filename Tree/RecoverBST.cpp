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

void recoverTree(TreeNode *root)
{
    TreeNode *wrong1 = NULL;
    TreeNode *wrong2 = NULL;
    TreeNode *wrong3 = NULL;
    TreeNode *prev = NULL;
    bool flag = true;

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
            TreeNode *top = st.top();
            st.pop();

            if (prev != NULL && prev->val > top->val)
            {
                if (flag)
                {
                    wrong1 = prev;
                    wrong2 = top;
                    flag = false;
                }
                else
                {
                    wrong3 = top;
                }
            }
            prev = top;

            if (top->right != NULL)
                st.push(top->right);
            curr = top->right;
        }
    }

    if (wrong3 == NULL)
    {
        int data = wrong1->val;
        wrong1->val = wrong2->val;
        wrong2->val = data;
    }
    else
    {
        int data = wrong1->val;
        wrong1->val = wrong3->val;
        wrong3->val = data;
    }
}

int main()
{
    return 0;
}