#include "bits/stdc++.h"
using namespace std;

vector<int> topKFrequent(vector<int> &nums, int k)
{
    unordered_map<int, int> freq;
    for (int i = 0; i < nums.size(); ++i)
        freq[nums[i]]++;

    priority_queue<pair<int, int>> pq;
    for (auto it : freq)
        pq.push({it.second, it.first});

    vector<int> ans;
    for (int i = 0; i < k; ++i)
    {
        if (!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        else
        {
            break;
        }
    }
    return ans;
}

int main()
{

    return 0;
}