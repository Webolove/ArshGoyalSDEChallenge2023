#include "bits/stdc++.h"
using namespace std;

void bfs(int node, vector<int> adj[], vector<int> &res, vector<bool> &visited)
{
    queue<int> q;
    q.push(node);
    visited[node] = true;

    int frontnode;
    while (!q.empty())
    {
        frontnode = q.front();
        q.pop();
        res.push_back(frontnode);
        for (auto i : adj[frontnode])
        {
            if (!visited[i])
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}
vector<int> bfsOfGraph(int V, vector<int> adj[])
{
    vector<bool> visited(V, false);
    vector<int> res;

    for (int i = 0; i < V; ++i)
    {
        if (!visited[i])
            bfs(i, adj, res, visited);
    }

    return res;
}

int main()
{

    return 0;
}