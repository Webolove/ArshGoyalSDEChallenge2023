#include "bits/stdc++.h"
using namespace std;

int maximalSquare(vector<vector<char>> &matrix)
{
    int maxi = 0;
    vector<vector<int>> grid(matrix.size(), vector<int>(matrix[0].size(), 0));
    for (int i = 0; i < matrix.size(); ++i)
    {
        if (matrix[i][0] == '1')
            maxi = 1;
        grid[i][0] = matrix[i][0] - '0';
    }

    for (int i = 0; i < matrix[0].size(); ++i)
    {
        if (matrix[0][i] == '1')
            maxi = 1;
        grid[0][i] = matrix[0][i] - '0';
    }

    for (int i = 1; i < matrix.size(); ++i)
    {
        for (int j = 1; j < matrix[0].size(); ++j)
        {
            if (matrix[i][j] != '0')
            {
                int a = grid[i - 1][j];
                int b = grid[i][j - 1];
                int c = grid[i - 1][j - 1];
                grid[i][j] = 1 + min(a, min(b, c));
                if (maxi < 1 + min(a, min(b, c)))
                    maxi = 1 + min(a, min(b, c));
            }
        }
    }
    return maxi * maxi;
}

int main()
{

    return 0;
}