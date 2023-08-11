#include "bits/stdc++.h"
using namespace std;

vector<int> drow = {-1, 0, 1, 0};
vector<int> dcol = {0, -1, 0, 1};
int solve(int row, int col, vector<vector<int>> grid, vector<vector<bool>> &vis)
{
    if (grid[row][col] == 2)
    {
        vis[row][col] = true;
        bool flag = true;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (!vis[i][j])
                {
                    vis[row][col] = false;
                    return 0;
                }
            }
        }
        vis[row][col] = false;
        return 1;
    }

    int count = 0;
    vis[row][col] = true;
    for (int i = 0; i < 4; ++i)
    {
        int newRow = row + drow[i];
        int newCol = col + dcol[i];
        if (newRow >= 0 && newCol >= 0 && newRow < grid.size() && newCol < grid[0].size())
        {
            if (!vis[newRow][newCol])
                count += solve(newRow, newCol, grid, vis);
        }
    }
    vis[row][col] = false;
    return count;
}
int uniquePathsIII(vector<vector<int>> &grid)
{
    vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(), false));
    int startRow = 0, startCol = 0;
    for (int i = 0; i < grid.size(); ++i)
    {
        for (int j = 0; j < grid[0].size(); ++j)
        {
            if (grid[i][j] == 1)
            {
                startRow = i;
                startCol = j;
            }
            else if (grid[i][j] == -1)
                vis[i][j] = true;
        }
    }
    return solve(startRow, startCol, grid, vis);
}

int main()
{

    return 0;
}