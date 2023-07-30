// find-the-city-with-the-smallest-number-of-neighbors-at-threshold-distance

#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int dijkstra(int source, unordered_map<int, vector<pair<int, int>>> adj, int threshold, int totalCity)
    {
        vector<int> shortestDist(totalCity, INT_MAX);
        shortestDist[source] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, source});

        while (!pq.empty())
        {
            int node = pq.top().second;
            int dist = pq.top().first;
            pq.pop();

            if (dist >= threshold)
                continue;

            for (auto it : adj[node])
            {
                if (it.second + dist < shortestDist[it.first])
                {
                    shortestDist[it.first] = it.second + dist;
                    pq.push({shortestDist[it.first], it.first});
                }
            }
        }
        int count = 0;
        for (int i = 0; i < shortestDist.size(); ++i)
        {
            if (shortestDist[i] <= threshold)
                count++;
        }
        return count;
    }

    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        // This vector will store count of all cities reachable from city i where i is the index.
        vector<int> citiesReachable(n, INT_MAX);

        // Creating adj list.
        unordered_map<int, vector<pair<int, int>>> adj;
        for (int i = 0; i < edges.size(); ++i)
        {
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }

        int ans = INT_MAX;
        int city = 0;
        for (int i = 0; i < n; ++i)
        {
            citiesReachable[i] = dijkstra(i, adj, distanceThreshold, n);
            if (ans >= citiesReachable[i])
            {
                ans = citiesReachable[i];
                city = i;
            }
        }
        return city;
    }
};

int main()
{

    return 0;
}