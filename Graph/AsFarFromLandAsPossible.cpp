#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int maxDistance(vector<vector<int>> &grid)
    {
        queue<pair<pair<int, int>, int>> qu; // {{row, col}, dist}
        int n = grid.size();
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 1)
                    qu.push({{i, j}, 0});
            }
        }
        int ans = -1;
        vector<int> drow = {-1, 0, 1, 0};
        vector<int> dcol = {0, -1, 0, 1};
        while (!qu.empty())
        {
            int row = qu.front().first.first;
            int col = qu.front().first.second;
            int dist = qu.front().second;
            qu.pop();

            for (int i = 0; i < 4; ++i)
            {
                int newRow = row + drow[i];
                int newCol = col + dcol[i];
                if (newRow >= 0 && newCol >= 0 && newRow < n && newCol < n && grid[newRow][newCol] != 1)
                {
                    grid[newRow][newCol] = 1;
                    qu.push({{newRow, newCol}, dist + 1});
                    ans = max(ans, dist + 1);
                }
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}