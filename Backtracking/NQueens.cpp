#include "bits/stdc++.h"
using namespace std;

bool isValid(int row, int col, vector<string> oneSol)
{
    int i = row - 1;
    while (i >= 0)
    {
        if (oneSol[i][col] == 'Q')
            return false;
        i--;
    }
    i = row - 1;
    int j = col - 1;
    while (i >= 0 && j >= 0)
    {
        if (oneSol[i][j] == 'Q')
            return false;
        i--;
        j--;
    }
    i = row - 1;
    j = col + 1;
    while (i >= 0 && j < oneSol[0].size())
    {
        if (oneSol[i][j] == 'Q')
            return false;
        i--;
        j++;
    }

    return true;
}
void nQueens(int row, int n, vector<string> &oneSol, vector<vector<string>> &result)
{
    if (row >= n)
        result.push_back(oneSol);

    for (int col = 0; col < n; ++col)
    {
        if (isValid(row, col, oneSol))
        {
            oneSol[row][col] = 'Q';
            nQueens(row + 1, n, oneSol, result);
            oneSol[row][col] = '.';
        }
    }
}
vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> result;

    string str = "";
    for (int i = 0; i < n; ++i)
        str += '.';
    vector<string> oneSol(n, str);

    nQueens(0, n, oneSol, result);

    return result;
}

int main()
{

    return 0;
}