#include "bits/stdc++.h"
using namespace std;

class DisjointSet
{
public:
    vector<int> Size, parent;
    DisjointSet(int n)
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
};
class Solution
{
public:
    int largestIsland(vector<vector<int>> &grid)
    {
        int n = grid.size();
        DisjointSet ds(n * n);

        bool flag = true;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 1)
                {
                    int node = i * n + j;

                    vector<int> drow = {-1, 0, 1, 0};
                    vector<int> dcol = {0, -1, 0, 1};
                    for (int k = 0; k < 4; ++k)
                    {
                        int adjrow = i + drow[k];
                        int adjcol = j + dcol[k];
                        int adjNode = adjrow * n + adjcol;
                        if (adjrow < n && adjcol < n && adjrow >= 0 && adjcol >= 0 && grid[adjrow][adjcol] == 1)
                            ds.UnionBySize(adjNode, node);
                    }
                }
                else
                    flag = false;
            }
        }
        if (flag)
            return n * n;

        int ans = 0;

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 0)
                {

                    int count = 1;
                    set<int> parentSet;
                    vector<int> drow = {-1, 0, 1, 0};
                    vector<int> dcol = {0, -1, 0, 1};
                    for (int k = 0; k < 4; ++k)
                    {
                        int adjrow = i + drow[k];
                        int adjcol = j + dcol[k];
                        int adjNode = adjrow * n + adjcol;
                        if (adjrow < n && adjcol < n && adjrow >= 0 && adjcol >= 0 && grid[adjrow][adjcol] == 1)
                        {
                            int ult_Parent_AdjNode = ds.findUltParent(adjNode);
                            if (parentSet.find(ult_Parent_AdjNode) == parentSet.end())
                            {
                                count += ds.Size[ult_Parent_AdjNode];
                                parentSet.insert(ult_Parent_AdjNode);
                            }
                        }
                    }
                    ans = max(ans, count);
                }
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}