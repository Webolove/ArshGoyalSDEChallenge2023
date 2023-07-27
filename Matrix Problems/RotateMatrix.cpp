#include "bits/stdc++.h"
using namespace std;

void rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    if (n == 1)
        return;
    else if (n == 2)
    {
        int temp = matrix[0][0];
        matrix[0][0] = matrix[1][0];
        matrix[1][0] = matrix[1][1];
        matrix[1][1] = matrix[0][1];
        matrix[0][1] = temp;
        return;
    }
    for (int i = 0; i < n - 2; ++i)
    {
        for (int j = i; j < n - i - 1; ++j)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[n - j - 1][i];
            matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
            matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
            matrix[j][n - i - 1] = temp;
        }
    }
}

int main()
{

    return 0;
}