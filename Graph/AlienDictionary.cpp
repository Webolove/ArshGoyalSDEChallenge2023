#include "bits/stdc++.h"
using namespace std;

string findOrder(string dict[], int N, int K)
{
    vector<vector<int>> adj(K);
    for (int i = 0; i < N - 1; ++i)
    {
        int char1 = 0, char2 = 0;
        while (char1 < dict[i].size() && char2 < dict[i + 1].size())
        {
            if (dict[i][char1] != dict[i + 1][char2])
            {
                int val1 = dict[i][char1] - 'a';
                int val2 = dict[i + 1][char2] - 'a';
                adj[val1].push_back(val2);
                break;
            }
            char1++;
            char2++;
        }
    }
    vector<int> indegree(K, 0);
    for (int i = 0; i < K; ++i)
    {
        for (auto it : adj[i])
            indegree[it]++;
    }
    queue<int> qu;
    for (int i = 0; i < K; ++i)
    {
        if (indegree[i] == 0)
            qu.push(i);
    }
    vector<int> res;
    while (!qu.empty())
    {
        int node = qu.front();
        qu.pop();
        res.push_back(node);
        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
                qu.push(it);
        }
    }
    string ans = "";

    for (int i = 0; i < K; ++i)
        ans += 97 + res[i];
    while (ans.size() != K)
        ans += 97 + (K - ans.size());

    return ans;
}

int main()
{

    return 0;
}