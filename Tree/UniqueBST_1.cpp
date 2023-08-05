#include "bits/stdc++.h"
using namespace std;

unordered_map<int, int> dp;
int numTrees(int n)
{
    if (n == 0)
        return 1;
    if (n <= 2)
        return n;
    if (dp.find(n) != dp.end())
        return dp[n];

    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        int leftNodes = i - 1;
        int rightNodes = n - i;
        ans += numTrees(leftNodes) * numTrees(rightNodes);
    }
    return dp[n] = ans;
}

int main()
{
    return 0;
}