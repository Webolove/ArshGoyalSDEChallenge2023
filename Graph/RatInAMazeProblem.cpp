#include "bits/stdc++.h"
using namespace std;

vector<int> drow = {-1, 0, 1, 0};
vector<int> dcol = {0, -1, 0, 1};
vector<string> movement = {"U", "L", "D", "R"};
void dfs(int row, int col, int n, vector<vector<int>> &m, vector<vector<bool>> &vis, string str, vector<string> &ans)
{
    if (row == n - 1 && col == n - 1)
    {
        ans.push_back(str);
        return;
    }
    vis[row][col] = true;

    for (int i = 0; i < 4; ++i)
    {
        int newRow = row + drow[i];
        int newCol = col + dcol[i];
        if (newRow >= 0 && newCol >= 0 && newRow < n && newCol < n && !vis[newRow][newCol] && m[newRow][newCol] != 0)
            dfs(newRow, newCol, n, m, vis, str + movement[i], ans);
    }

    vis[row][col] = false;
}
vector<string> findPath(vector<vector<int>> &m, int n)
{
    vector<string> ans;

    if (m[0][0] == 0 || m[n - 1][n - 1] == 0)
        return ans;

    string str = "";
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    dfs(0, 0, n, m, vis, str, ans);
    return ans;
}

int main()
{

    return 0;
}