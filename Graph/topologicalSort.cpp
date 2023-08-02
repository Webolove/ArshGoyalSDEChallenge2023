#include "bits/stdc++.h"
using namespace std;

void dfs(int node, vector<bool> &vis, vector<int> adj[], vector<int> &ans)
{
    vis[node] = true;

    for (auto it : adj[node])
    {
        if (!vis[it])
            dfs(it, vis, adj, ans);
    }
    ans.push_back(node);
}
vector<int> topoSort(int V, vector<int> adj[])
{
    vector<int> ans;
    vector<bool> vis(V, false);
    for (int i = 0; i < V; ++i)
    {
        if (!vis[i])
            dfs(i, vis, adj, ans);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{

    return 0;
}