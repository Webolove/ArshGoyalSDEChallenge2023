#include "bits/stdc++.h"
using namespace std;

int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
{
    vector<vector<vector<int>>> adj(n);
    for (int i = 0; i < flights.size(); ++i)
        adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});

    queue<vector<int>> qu;
    vector<int> costs(n, INT_MAX);
    costs[src] = 0;
    qu.push({0, src, 0});
    while (!qu.empty())
    {
        int steps = qu.front()[0];
        int node = qu.front()[1];
        int cost = qu.front()[2];
        qu.pop();

        if (steps == k + 1)
            continue;

        for (auto it : adj[node])
        {
            if (cost + it[1] < costs[it[0]])
            {
                costs[it[0]] = cost + it[1];
                qu.push({steps + 1, it[0], costs[it[0]]});
            }
        }
    }
    if (costs[dst] == INT_MAX)
        return -1;
    return costs[dst];
}

int main()
{

    return 0;
}