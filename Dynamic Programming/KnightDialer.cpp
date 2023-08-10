#include "bits/stdc++.h"
using namespace std;

vector<int> drow = {-2, -2, -1, -1, 1, 1, 2, 2};
vector<int> dcol = {-1, 1, -2, 2, -2, 2, -1, 1};
int mod = 1e9 + 7;

int dfs(int row, int col, int n, vector<vector<vector<int>>> &dp)
{
    if ((row == 3 && col == 0) || (row == 3 && col == 2))
        return 0;
    if (n == 1)
        return 1;
    if (dp[row][col][n] != -1)
        return dp[row][col][n];

    int count = 0;
    for (int i = 0; i < 8; ++i)
    {
        int newRow = row + drow[i];
        int newCol = col + dcol[i];

        if (newRow >= 0 && newCol >= 0 && newRow < 4 && newCol < 3)
            count = (count + dfs(newRow, newCol, n - 1, dp)) % mod;
    }
    return dp[row][col][n] = count % mod;
}

int knightDialer(int n)
{
    int ans = 0;
    vector<vector<vector<int>>> dp(4, vector<vector<int>>(3, vector<int>(n + 1, -1)));
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 3; ++j)
            ans = (ans + dfs(i, j, n, dp)) % mod;
    }
    return ans;
}

int main()
{

    return 0;
}