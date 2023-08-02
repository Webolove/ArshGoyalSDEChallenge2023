#include "bits/stdc++.h"
using namespace std;

int dfs(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &matrix)
{
    if (grid[row][col] != 0)
        return grid[row][col];

    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> drow = {-1, 1, 0, 0};
    vector<int> dcol = {0, 0, -1, 1};
    int count = 1;
    int value = 0;
    for (int i = 0; i < 4; ++i)
    {
        int adjRow = row + drow[i];
        int adjCol = col + dcol[i];
        if (adjRow < n && adjCol < m && adjRow >= 0 && adjCol >= 0)
        {
            if (matrix[adjRow][adjCol] > matrix[row][col])
                value = max(dfs(adjRow, adjCol, grid, matrix), value);
        }
    }
    count += value;
    return grid[row][col] = count;
}
int longestIncreasingPath(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> grid(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
            dfs(i, j, grid, matrix);
    }
    int ans;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
            ans = max(ans, grid[i][j]);
    }
    return ans;
}

int main()
{

    return 0;
}