#include "bits/stdc++.h"
using namespace std;

bool dfs(int node, int parent, vector<int> adj[], vector<bool> &vis)
{
    vis[node] = true;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            if (dfs(it, node, adj, vis))
                return true;
        }
        else if (it != parent)
            return true;
    }
    return false;
}
bool isCycle(int V, vector<int> adj[])
{
    vector<bool> visited(V, false);
    for (int i = 0; i < V; ++i)
    {
        if (!visited[i])
        {
            if (dfs(i, -1, adj, visited))
                return true;
        }
    }
    return false;
}

int main()
{

    return 0;
}