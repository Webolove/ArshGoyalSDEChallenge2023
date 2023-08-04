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

class BSTIterator
{
public:
    // We don't create the whole inorder in a go, instead we push all left elem in a stack
    // And whenever the next is called we check does the top element have anything on right
    // if yes, then we again push all left elem. of top's right

    stack<TreeNode *> st;
    BSTIterator(TreeNode *root)
    {
        TreeNode *temp = root;
        while (temp != NULL)
        {
            st.push(temp);
            temp = temp->left;
        }
    }

    int next()
    {
        if (!st.empty())
        {
            TreeNode *top = st.top();
            st.pop();

            int res = top->val;
            TreeNode *temp = top->right;

            while (temp != NULL)
            {
                st.push(temp);
                temp = temp->left;
            }

            return res;
        }
        else
            return -1;
    }

    bool hasNext()
    {
        return !st.empty();
    }
};

int main()
{

    return 0;
}