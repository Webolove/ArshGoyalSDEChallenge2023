#include "bits/stdc++.h"
using namespace std;

int timer = 0;
void dfs(int node, int parent, vector<bool> &vis, vector<int> &insertiontime, vector<int> &low, vector<vector<int>> &adj, vector<vector<int>> &bridges)
{
    vis[node] = true;
    insertiontime[node] = timer;
    low[node] = timer;
    timer++;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, node, vis, insertiontime, low, adj, bridges);
            low[node] = min(low[node], low[it]);
            if (low[it] > insertiontime[node])
                bridges.push_back({node, it});
        }
        else if (it != parent)
            low[node] = min(low[node], low[it]);
    }
}
vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
{
    vector<vector<int>> adj(n);
    for (int i = 0; i < connections.size(); ++i)
    {
        adj[connections[i][0]].push_back(connections[i][1]);
        adj[connections[i][1]].push_back(connections[i][0]);
    }

    vector<int> insertionTime(n);
    vector<int> low(n);
    vector<bool> vis(n, false);
    vector<vector<int>> bridges;
    dfs(0, -1, vis, insertionTime, low, adj, bridges);
    return bridges;
}

int main()
{

    return 0;
}