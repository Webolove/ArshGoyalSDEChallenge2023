#include "bits/stdc++.h"
using namespace std;

void isALiveCell(int row, int col, vector<vector<int>> Cpy, vector<vector<int>> &board)
{
    int count = 0;
    for (int i = row - 1; i <= row + 1; ++i)
    {
        for (int j = col - 1; j <= col + 1; ++j)
        {
            if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || (i == row && j == col))
                continue;

            if (Cpy[i][j] == 1)
                count++;
        }
    }
    if (count < 2 || count > 3)
        board[row][col] = 0;
}

void isADeadCell(int row, int col, vector<vector<int>> Cpy, vector<vector<int>> &board)
{
    int count = 0;
    for (int i = row - 1; i <= row + 1; ++i)
    {
        for (int j = col - 1; j <= col + 1; ++j)
        {
            if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || (i == row && j == col))
                continue;

            if (Cpy[i][j] == 1)
                count++;
        }
    }
    if (count == 3)
        board[row][col] = 1;
}
void gameOfLife(vector<vector<int>> &board)
{
    vector<vector<int>> myCopy = board;
    for (int i = 0; i < board.size(); ++i)
    {
        for (int j = 0; j < board[0].size(); ++j)
        {
            if (board[i][j] == 0)
                isADeadCell(i, j, myCopy, board);
            else
                isALiveCell(i, j, myCopy, board);
        }
    }
}

int main()
{

    return 0;
}