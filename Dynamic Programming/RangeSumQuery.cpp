#include "bits/stdc++.h"
using namespace std;

class NumMatrix
{
public:
    vector<vector<int>> table;
    NumMatrix(vector<vector<int>> &matrix)
    {
        table = matrix;
        int n = matrix.size(), m = matrix[0].size();
        for (int i = 0; i < n; ++i)
        {
            int left = 0;
            for (int j = 0; j < m; ++j)
            {
                left += matrix[i][j];
                table[i][j] = left;
                if (i != 0)
                    table[i][j] += table[i - 1][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        int ans = table[row2][col2];
        if (row1 - 1 >= 0)
            ans -= table[row1 - 1][col2];
        if (col1 - 1 >= 0)
            ans -= table[row2][col1 - 1];
        if (row1 - 1 >= 0 && col1 - 1 >= 0)
            ans += table[row1 - 1][col1 - 1];
        return ans;
    }
};

int main()
{

    return 0;
}