#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        int V = graph.size();
        vector<vector<int>> reverseAdj(V);
        vector<int> indegree(V);
        queue<int> qu;
        for (int i = 0; i < V; ++i)
        {
            for (int j = 0; j < graph[i].size(); ++j)
                reverseAdj[graph[i][j]].push_back(i);

            indegree[i] = graph[i].size();
            if (indegree[i] == 0)
                qu.push(i);
        }
        vector<int> res;
        while (!qu.empty())
        {
            int node = qu.front();
            qu.pop();
            res.push_back(node);
            for (auto it : reverseAdj[node])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                    qu.push(it);
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};

int main()
{

    return 0;
}