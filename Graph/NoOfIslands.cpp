#include "bits/stdc++.h"
using namespace std;

void dfs(int i, int j, vector<vector<char>> &grid)
{
    grid[i][j] = '0';
    if ((i - 1) >= 0)
    {
        if (grid[i - 1][j] == '1')
            dfs(i - 1, j, grid);
    }
    if ((i + 1) < grid.size())
    {
        if (grid[i + 1][j] == '1')
            dfs(i + 1, j, grid);
    }
    if ((j - 1) >= 0)
    {
        if (grid[i][j - 1] == '1')
            dfs(i, j - 1, grid);
    }
    if ((j + 1) < grid[0].size())
    {
        if (grid[i][j + 1] == '1')
            dfs(i, j + 1, grid);
    }
}
int numIslands(vector<vector<char>> &grid)
{
    int count = 0;
    for (int i = 0; i < grid.size(); ++i)
    {
        for (int j = 0; j < grid[0].size(); ++j)
        {
            if (grid[i][j] == '1')
            {
                dfs(i, j, grid);
                count++;
            }
        }
    }
    return count;
}

int main()
{

    return 0;
}