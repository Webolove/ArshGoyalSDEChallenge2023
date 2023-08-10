#include "bits/stdc++.h"
using namespace std;

int minPathSum(vector<vector<int>> &grid)
{
    vector<int> front(grid[0].size() + 1, 1e8), curr(grid[0].size() + 1, 0);
    curr[1] = grid[0][0];

    for (int i = 1; i <= grid.size(); ++i)
    {
        curr[0] = 1e8;
        for (int j = 1; j <= grid[0].size(); ++j)
        {
            if (i == 1 && j == 1)
                continue;
            int left = grid[i - 1][j - 1] + curr[j - 1];
            int up = grid[i - 1][j - 1] + front[j];
            curr[j] = min(left, up);
        }
        front = curr;
    }

    return front[grid[0].size()];
}

int main()
{

    return 0;
}