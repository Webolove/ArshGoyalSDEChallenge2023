#include "bits/stdc++.h"
using namespace std;

// Statement : There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where connections[i] = [ai, bi] represents a connection between computers ai and bi. Any computer can reach any other computer directly or indirectly through the network.

// You are given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected.

// Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return -1.

class disjointset
{
    vector<int> parent, rank;

public:
    disjointset(int n)
    {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int findUltParent(int u)
    {
        if (u == parent[u])
            return u;
        return parent[u] = findUltParent(parent[u]);
    }

    void Union(int u, int v)
    {
        int ult_pu = findUltParent(u);
        int ult_pv = findUltParent(v);
        if (rank[ult_pu] > rank[ult_pv])
            parent[ult_pv] = ult_pu;
        else if (rank[ult_pu] < rank[ult_pv])
            parent[ult_pu] = ult_pv;
        else
        {
            parent[ult_pu] = ult_pv;
            rank[ult_pv]++;
        }
    }

    int count()
    {
        int cunt = 0;
        for (int i = 0; i < parent.size(); ++i)
        {
            if (parent[i] == i)
                cunt++;
        }
        return cunt;
    }
};

class Solution
{
public:
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        disjointset ds(n);
        int cycleFormingEdges = 0;
        for (int i = 0; i < connections.size(); ++i)
        {
            if (ds.findUltParent(connections[i][0]) == ds.findUltParent(connections[i][1]))
                cycleFormingEdges++;
            else
                ds.Union(connections[i][0], connections[i][1]);
        }
        int independentComp = ds.count();
        int minEdgesRequired = independentComp - 1; // For connecting n components we require minimum of n - 1 edges.
        if (minEdgesRequired > cycleFormingEdges)
            return -1;
        else
            return minEdgesRequired;
    }
};

int main()
{

    return 0;
}