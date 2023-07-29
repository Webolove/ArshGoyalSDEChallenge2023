#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int dfs(int node, unordered_map<int, vector<int>> adj, vector<int> informTime)
    {

        int ans = informTime[node];
        int nextEmployeeTime = 0;
        for (auto it : adj[node])
            nextEmployeeTime = max(nextEmployeeTime, dfs(it, adj, informTime));
        return ans + nextEmployeeTime;
    }

    int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime)
    {
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < manager.size(); ++i)
            adj[manager[i]].push_back(i);

        // return dfs(headID, adj, informTime);
        queue<pair<int, int>> qu; // pair{Id, time};
        qu.push({headID, 0});

        int ans = 0;
        while (!qu.empty())
        {
            int size = qu.size();
            for (int i = 0; i < size; ++i)
            {
                int node = qu.front().first;
                int timer = qu.front().second;
                ans = max(ans, timer);
                qu.pop();

                for (auto it : adj[node])
                    qu.push({it, timer + informTime[node]});
            }
        }
        return ans;
    }
};

/*
    say root node take 1 unit of time to inform it's children
    Therefore, its children will get infromation after 1 unit time
    Say the left branch takes 2 unit time to inform
    Therefore, the children of left branch will take 2 + 1 = 3 unit of time in total
    and similarly for the right branch.
              0
           /    \
          1      1
        /  \    / \
       3    3  4   4
*/

int main()
{

    return 0;
}