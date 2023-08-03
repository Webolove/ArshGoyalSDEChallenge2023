#include "bits/stdc++.h"
using namespace std;

void findRowCol(int &row, int &col, int N, int newNode)
{
    row = N - (newNode / N) - 1;
    int startVal = (N - row - 1) * N;

    if (N % 2 == 0)
    {
        if (row % 2 == 0)
            col = N - (newNode - startVal) - 1;
        else
            col = (newNode - startVal);
    }
    else
    {
        if (row % 2 != 0)
            col = N - (newNode - startVal) - 1;
        else
            col = (newNode - startVal);
    }
}

int snakesAndLadders(vector<vector<int>> &board)
{
    int N = board.size();

    vector<vector<bool>> vis(N, vector<bool>(N, false));

    // we are considering that count starts from 0 and going to n*n - 1;
    queue<pair<int, int>> pq;
    // {node, dist}
    pq.push({0, 0});
    int ans = INT_MAX;

    while (!pq.empty())
    {
        int node = pq.front().first;
        int dist = pq.front().second;
        pq.pop();

        if (node == N * N - 1)
        {
            ans = min(ans, dist);
            continue;
        }

        for (int i = 1; i <= 6; ++i)
        {
            int newNode = min(node + i, N * N - 1);

            // finding corresponding row and col for the newNode
            int row = 0;
            int col = 0;
            findRowCol(row, col, N, newNode);

            if (board[row][col] != -1)
            {
                newNode = board[row][col] - 1;
                findRowCol(row, col, N, newNode);
            }
            if (!vis[row][col])
            {
                pq.push({newNode, dist + 1});
                vis[row][col] = true;
            }
        }
    }
    if (ans == INT_MAX)
        return -1;
    return ans;
}

int main()
{

    return 0;
}