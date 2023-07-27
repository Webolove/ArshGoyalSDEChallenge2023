#include "bits/stdc++.h"
using namespace std;

void dfs(int node, unordered_map<int, vector<int>> adj, vector<int> &ans, vector<bool> &vis)
{
    vis[node] = true;
    ans.push_back(node);

    for (auto it : adj[node])
    {
        if (!vis[it])
            dfs(it, adj, ans, vis);
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    unordered_map<int, vector<int>> adj;
    for (int i = 0; i < E; ++i)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }

    vector<vector<int>> res;
    vector<bool> vis(V, false);
    for (int i = 0; i < V; ++i)
    {
        if (!vis[i])
        {
            vector<int> ans;
            dfs(i, adj, ans, vis);
            res.push_back(ans);
        }
    }
    return res;
}

int main()
{

    return 0;
}