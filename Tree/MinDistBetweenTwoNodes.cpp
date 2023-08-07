#include "bits/stdc++.h"
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void generate_adj(Node *root, unordered_map<int, vector<int>> &mp)
{
    if (root == NULL)
        return;
    if (root->left != NULL)
    {
        mp[root->data].push_back(root->left->data);
        mp[root->left->data].push_back(root->data);
    }
    if (root->right != NULL)
    {
        mp[root->data].push_back(root->right->data);
        mp[root->right->data].push_back(root->data);
    }
    generate_adj(root->left, mp);
    generate_adj(root->right, mp);
}

int findDist(Node *root, int a, int b)
{
    unordered_map<int, vector<int>> mp;
    generate_adj(root, mp);

    queue<int> qu;
    qu.push(a);

    unordered_map<int, bool> vis;
    vis[a] = true;
    bool found = false;

    int k = 0;

    while (!qu.empty())
    {
        int size = qu.size();

        for (int i = 0; i < size; ++i)
        {
            int node = qu.front();
            qu.pop();
            for (auto it : mp[node])
            {
                if (!vis[it])
                {
                    qu.push(it);
                    vis[it] = true;
                    if (it == b)
                    {
                        found = true;
                        break;
                    }
                }
            }
            if (found)
                break;
        }

        k++;
        if (found)
            return k;
    }
    return 0;
}

int main()
{
    return 0;
}