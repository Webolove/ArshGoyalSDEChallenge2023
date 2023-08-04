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

class DisjointSet
{
    vector<int> parent, rank;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; ++i)
            parent[i] = i;
    }

    int findUltParent(int n)
    {
        if (n == parent[n])
            return n;
        return parent[n] = findUltParent(parent[n]);
    }

    void unionByRank(int u, int v)
    {
        int ult_pu = findUltParent(u);
        int ult_pv = findUltParent(v);
        if (ult_pu == ult_pv)
            return;

        if (rank[ult_pu] > rank[ult_pv])
            parent[ult_pv] = ult_pu;
        else if (rank[ult_pu] < rank[ult_pv])
            parent[ult_pu] = ult_pv;
        else
        {
            parent[ult_pu] = ult_pv;
            rank[ult_pv]++;
        }
    }
};
class Solution
{
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        DisjointSet ds(edges.size());
        vector<int> ans;
        for (int i = 0; i < edges.size(); ++i)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int ult_u = ds.findUltParent(u);
            int ult_v = ds.findUltParent(v);
            if (ult_u == ult_v)
                ans = {u, v};
            ds.unionByRank(u, v);
        }
        return ans;
    }
};

int main()
{

    return 0;
}