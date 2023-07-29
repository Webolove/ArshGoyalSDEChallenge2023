#include "bits/stdc++.h"
using namespace std;

class disjointSet
{
    vector<int> Size, parent;

public:
    disjointSet(int n)
    {
        Size.resize(n, 1);
        parent.resize(n);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int findUltParent(int u)
    {
        if (u == parent[u])
            return u;
        return parent[u] = findUltParent(parent[u]);
    }

    void UnionBySize(int u, int v)
    {
        int ult_pu = findUltParent(u);
        int ult_pv = findUltParent(v);

        if (ult_pu == ult_pv)
            return;

        if (Size[ult_pu] > Size[ult_pv])
        {
            parent[ult_pv] = ult_pu;
            Size[ult_pu] += Size[ult_pv];
        }
        else
        {
            parent[ult_pu] = ult_pv;
            Size[ult_pv] += Size[ult_pu];
        }
    }

    int total_comp()
    {
        int count = 0;
        for (int i = 0; i < parent.size(); ++i)
        {
            if (parent[i] == i && Size[i] > 1)
                count++;
        }
        return count;
    }
};
class Solution
{
public:
    int removeStones(vector<vector<int>> &stones)
    {
        int n = stones.size();
        int total_rows = 0, total_cols = 0;
        for (int i = 0; i < n; ++i)
        {
            total_rows = max(total_rows, stones[i][0]);
            total_cols = max(total_cols, stones[i][1]);
        }

        // Creating disjoint set where nodes represent the rows and columns
        disjointSet ds(total_rows + total_cols + 2); // +2 is done because index starts with value 0. So, if total_rows = 3, it will eventually means there are 4 rows and similarly for total_cols.

        for (int i = 0; i < n; ++i)
        {
            int row = stones[i][0];
            int col = stones[i][1];
            int true_col = col + total_rows + 1; // since, node 0 is already representing row 0, therefore we have to find a true column value which will start from the end of row value. for example if there are 5 rows then total_rows = 4 then col will start from "0 + 4 + 1 = 5".
            ds.UnionBySize(row, true_col);
        }

        int total_components = ds.total_comp();
        return n - total_components;
    }
};

int main()
{

    return 0;
}