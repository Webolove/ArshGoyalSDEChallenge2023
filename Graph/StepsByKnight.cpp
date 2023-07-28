#include "bits/stdc++.h"
using namespace std;

vector<int> drow = {-2, -2, -1, -1, 1, 1, 2, 2};
vector<int> dcol = {-1, 1, -2, 2, -2, 2, -1, 1};

// Function to find out minimum steps Knight needs to reach target position.
int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int N)
{
    queue<pair<int, int>> qu;
    qu.push({KnightPos[0] - 1, KnightPos[1] - 1});

    vector<vector<bool>> vis(N, vector<bool>(N, false));
    vis[KnightPos[0] - 1][KnightPos[1] - 1] = true;
    int level = 0;
    while (!qu.empty())
    {
        int size = qu.size();
        for (int i = 0; i < size; ++i)
        {
            int frontRow = qu.front().first;
            int frontCol = qu.front().second;
            qu.pop();

            if (frontRow == TargetPos[0] - 1 && frontCol == TargetPos[1] - 1)
                return level;

            for (int i = 0; i < 8; ++i)
            {
                int newRow = frontRow + drow[i];
                int newCol = frontCol + dcol[i];

                if (newRow < N && newCol < N && newRow >= 0 && newCol >= 0)
                {
                    if (!vis[newRow][newCol])
                    {
                        vis[newRow][newCol] = true;
                        qu.push({newRow, newCol});
                    }
                }
            }
        }
        level++;
    }
    return level;
}

int main()
{

    return 0;
}