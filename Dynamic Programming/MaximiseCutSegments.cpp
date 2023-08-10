#include "bits/stdc++.h"
using namespace std;

int solve(int n, int arr[], vector<int> &dp)
{
    if (n < 0)
        return INT_MIN;
    if (n == 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];

    int count = 0;
    int ans = INT_MIN;
    for (int i = 0; i < 3; ++i)
    {
        count = 1 + solve(n - arr[i], arr, dp);
        ans = max(ans, count);
    }
    return dp[n] = ans;
}

int main()
{

    return 0;
}