#include "bits/stdc++.h"
using namespace std;

class Kosaraju
{
public:
    // Function to find number of strongly connected components in the graph.
    void topoSort(int node, vector<vector<int>> &adj, vector<bool> &vis, stack<int> &st)
    {
        vis[node] = true;
        for (auto it : adj[node])
        {
            if (!vis[it])
                topoSort(it, adj, vis, st);
        }
        st.push(node);
    }
    int kosaraju(int V, vector<vector<int>> &adj)
    {
        vector<bool> vis(V, false);
        stack<int> st;
        for (int i = 0; i < V; ++i)
        {
            if (!vis[i])
                topoSort(i, adj, vis, st);
        }

        vector<vector<int>> reverseAdj(V);
        for (int i = 0; i < adj.size(); ++i)
        {
            for (int j = 0; j < adj[i].size(); ++j)
            {
                int u = adj[i][j];
                int v = i;
                reverseAdj[u].push_back(v);
            }
        }

        for (int i = 0; i < V; ++i)
            vis[i] = false;
        int count = 0;
        while (!st.empty())
        {
            if (!vis[st.top()])
            {
                count++;
                topoSort(st.top(), reverseAdj, vis, st);
            }
            st.pop();
        }

        return count;
    }
};

int main()
{

    return 0;
}