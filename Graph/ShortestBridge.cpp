#include "bits/stdc++.h"
using namespace std;

// My approach is as follow :
// At first I put all the row col value of any one of the island in my queue with dist 0 by making a dfs call for the first 1's i found while traversing in the grid
// This dfs call will make sure of two things 
// First one is obvious : putting row col together with distance 0 in queue
// second is that the 1's in this island is visited

// after the dfs call we run a while loop until the queue becomes empty.
// In each iteration, I check for its adjacent neighbours which are 0's and are not visited.
// if the adjacent neighbour is 0
// Then we mark it as true
// also, push a increased distance value with newRow newCol in queue 
// if adjacent neighbour is 1
// That means that we got our second island and so the dist till now can be a possible answer
// so, take out dist value and push nothing to queue.

vector<int> drow = {-1, 0, 1, 0};
vector<int> dcol = {0, -1, 0, 1};

void dfs(int row, int col, vector<vector<int>> &grid, vector<vector<bool>> &vis, queue<pair<int, pair<int, int>>> &qu)
{
    vis[row][col] = true;
    qu.push({0, {row, col}});

    for (int i = 0; i < 4; ++i)
    {
        int newRow = row + drow[i];
        int newCol = col + dcol[i];
        if (newRow >= 0 && newCol >= 0 && newRow < grid.size() && newCol < grid.size())
        {
            if (!vis[newRow][newCol] && grid[newRow][newCol] == 1)
                dfs(newRow, newCol, grid, vis, qu);
        }
    }
}

int shortestBridge(vector<vector<int>> &grid)
{
    int SM = grid.size();

    // Finding first row and col containing the 1's of any one island
    int row = 0, col = 0;
    bool flag = false;
    for (int i = 0; i < SM; ++i)
    {
        for (int j = 0; j < SM; ++j)
        {
            if (grid[i][j] == 1)
            {
                row = i;
                col = j;
                flag = true;
                break;
            }
        }
        if (flag)
            break;
    }

    vector<vector<bool>> vis(SM, vector<bool>(SM, false));
    queue<pair<int, pair<int, int>>> qu;
    dfs(row, col, grid, vis, qu);

    int ans = INT_MAX;
    while (!qu.empty())
    {
        int dist = qu.front().first;
        int row = qu.front().second.first;
        int col = qu.front().second.second;
        qu.pop();

        for (int i = 0; i < 4; ++i)
        {
            int newRow = row + drow[i];
            int newCol = col + dcol[i];
            if (newRow >= 0 && newCol >= 0 && newRow < grid.size() && newCol < grid.size())
            {
                if (!vis[newRow][newCol])
                {
                    if (grid[newRow][newCol] == 0)
                    {
                        qu.push({dist + 1, {newRow, newCol}});
                        vis[newRow][newCol] = true;
                    }
                    else
                        ans = min(ans, dist);
                }
            }
        }
    }
    return ans;
}

int main()
{

    return 0;
}