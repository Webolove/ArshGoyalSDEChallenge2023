#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    double dfs(string start, string target, unordered_map<string, vector<pair<string, double>>> adj, unordered_map<string, bool> &vis)
    {
        if (start == target)
            return 1;

        vis[start] = true;

        double ans = -1.00000;
        for (auto it : adj[start])
        {
            if (!vis[it.first])
                ans = max(ans, it.second * dfs(it.first, target, adj, vis));
        }
        return ans;
    }

    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        unordered_map<string, vector<pair<string, double>>> adj;
        for (int i = 0; i < values.size(); ++i)
        {
            adj[equations[i][0]].push_back({equations[i][1], values[i]});
            double rev = (double)1 / (double)values[i];
            adj[equations[i][1]].push_back({equations[i][0], rev});
        }
        for (auto it : adj)
        {
            cout << it.first << " -> ";
            for (auto bt : adj[it.first])
                cout << "{" << bt.first << " " << bt.second << " }, ";
            cout << endl;
        }
        vector<double> ans(queries.size(), -1.00000);

        for (int i = 0; i < queries.size(); ++i)
        {
            unordered_map<string, bool> vis;

            string startString = queries[i][0];
            string targetString = queries[i][1];

            // if either of startString and targetString doesn't exist in adj
            if (adj.find(startString) == adj.end() || adj.find(targetString) == adj.end())
                continue;

            // if Startstring and targetString both are same
            if (startString == targetString)
            {
                // if they belong to adj
                if (adj.find(startString) != adj.end())
                    ans[i] = 1.00000;
                // if they don't
                else
                    continue;
            }

            double res = dfs(startString, targetString, adj, vis);
            if (res >= 0)
                ans[i] = res;
        }
        return ans;
    }
};

int main()
{

    return 0;
}