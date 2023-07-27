#include "bits/stdc++.h"
using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    vector<int> res;
    int start_row = 0, start_col = 0;
    int end_row = matrix.size() - 1, end_col = matrix[0].size() - 1;
    vector<vector<bool>> vis(matrix.size(), vector<bool>(matrix[0].size(), false));
    while (start_row <= end_row && start_col <= end_col)
    {
        for (int i = start_col; i <= end_col; ++i)
        {
            if (!vis[start_row][i])
            {
                res.push_back(matrix[start_row][i]);
                vis[start_row][i] = true;
            }
        }
        start_row += 1;

        for (int i = start_row; i <= end_row; ++i)
        {
            if (!vis[i][end_col])
            {
                vis[i][end_col] = true;
                res.push_back(matrix[i][end_col]);
            }
        }
        end_col -= 1;

        for (int i = end_col; i >= start_col; i--)
        {
            if (!vis[end_row][i])
            {
                vis[end_row][i] = true;
                res.push_back(matrix[end_row][i]);
            }
        }
        end_row -= 1;

        for (int i = end_row; i >= start_row; i--)
        {
            if (!vis[i][start_col])
            {
                vis[i][start_col] = true;
                res.push_back(matrix[i][start_col]);
            }
        }
        start_col++;
    }
    return res;
}

int main()
{

    return 0;
}