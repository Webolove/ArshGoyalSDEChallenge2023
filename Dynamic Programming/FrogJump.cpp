#include "bits/stdc++.h"
using namespace std;

unordered_map<int, int> idxSrc;
unordered_map<int, unordered_map<int, int>> dp;

int binSrc(int start, int target)
{
    if (idxSrc.find(target) != idxSrc.end())
    {
        if (idxSrc[target] >= start)
            return idxSrc[target];
    }
    return -1;
}
bool solve(int idx, int prev_jump, vector<int> stones)
{
    if (idx >= stones.size() - 1)
        return true;
    if (dp.find(idx) != dp.end() && dp[idx].find(prev_jump) != dp[idx].end())
        return dp[idx][prev_jump];

    bool way1 = false, way2 = false, way3 = false;
    // move k + 1 step;
    int srcRes = binSrc(idx + 1, stones[idx] + prev_jump + 1);
    if (srcRes != -1)
        way1 = solve(srcRes, prev_jump + 1, stones);

    // move k step;
    srcRes = binSrc(idx + 1, stones[idx] + prev_jump);
    if (srcRes != -1)
        way2 = solve(srcRes, prev_jump, stones);

    // move k - 1 step;
    srcRes = binSrc(idx + 1, stones[idx] + prev_jump - 1);
    if (srcRes != -1)
        way3 = solve(srcRes, prev_jump - 1, stones);

    return dp[idx][prev_jump] = way1 || way2 || way3;
}
bool canCross(vector<int> &stones)
{
    for (int i = 0; i < stones.size(); ++i)
        idxSrc[stones[i]] = i;
    return solve(0, 0, stones);
}

int main()
{

    return 0;
}