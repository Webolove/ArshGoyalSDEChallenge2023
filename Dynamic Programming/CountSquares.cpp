#include "bits/stdc++.h"
using namespace std;

int countSquares(vector<vector<int>> &grid)
{
    vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), 0));

    int ans = 0;
    for (int i = 0; i < grid.size(); ++i)
    {
        dp[i][0] = grid[i][0];
        ans += dp[i][0];
    }
    for (int i = 1; i < grid[0].size(); ++i)
    {
        dp[0][i] = grid[0][i];
        ans += dp[0][i];
    }

    for (int i = 1; i < grid.size(); ++i)
    {
        for (int j = 1; j < grid[0].size(); ++j)
        {
            if (grid[i][j] == 1)
                dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
            else
                dp[i][j] = 0;
            ans += dp[i][j];
        }
    }
    return ans;
}

int main()
{

    return 0;
}