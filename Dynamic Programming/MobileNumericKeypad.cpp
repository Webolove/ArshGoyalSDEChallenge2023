#include "bits/stdc++.h"
using namespace std;

vector<int> drow = {-1, 0, 1, 0};
vector<int> dcol = {0, -1, 0, 1};

long long int solve(int row, int col, int n, vector<vector<vector<long long int>>> &dp)
{
    // cout << row << " " << col << " " << n << endl;
    if ((row == 3 && col == 0) || (row == 3 && col == 2))
        return 0;
    if (n <= 1)
        return 1;
    if (dp[row][col][n] != -1)
        return dp[row][col][n];

    long long count = solve(row, col, n - 1, dp);
    for (int i = 0; i < 4; ++i)
    {
        int newRow = row + drow[i];
        int newCol = col + dcol[i];
        if (newRow >= 0 && newCol >= 0 && newRow < 4 && newCol < 3)
        {
            count += solve(newRow, newCol, n - 1, dp);
        }
    }
    return dp[row][col][n] = count;
}
long long getCount(int N)
{
    long long ans = 0;
    vector<vector<vector<long long int>>> dp(4, vector<vector<long long int>>(3, vector<long long int>(N + 1, -1)));
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 3; ++j)
            ans += solve(i, j, N, dp);
    }
    return ans;
}

int main()
{

    return 0;
}