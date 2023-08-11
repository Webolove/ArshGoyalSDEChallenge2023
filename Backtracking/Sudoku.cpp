#include "bits/stdc++.h"
using namespace std;

bool isValid(int i, int j, char k, vector<vector<char>> board)
{
    for (int x = 0; x < 9; ++x)
    {
        if (board[i][x] == k || board[x][j] == k)
            return false;
        if (board[3 * (i / 3) + x / 3][3 * (j / 3) + x % 3] == k)
            return false;
    }
    // int box_row = (i % 3) * 3, box_col = (j % 3) * 3;
    // for(int x = box_row; x < box_row + 3; ++x)
    // {
    //     for(int y = box_col; y < box_col + 3; ++y)
    //     {
    //         if(board[x][y] == k)
    //             return false;
    //     }
    // }
    return true;
}
bool Sudoku(vector<vector<char>> &board)
{
    for (int i = 0; i < board.size(); ++i)
    {
        for (int j = 0; j < board[0].size(); ++j)
        {
            if (board[i][j] == '.')
            {

                for (char k = 49; k <= 57; ++k)
                {
                    if (isValid(i, j, k, board))
                    {
                        board[i][j] = k;
                        if (Sudoku(board))
                            return true;
                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}
void solveSudoku(vector<vector<char>> &board)
{
    Sudoku(board);
}

int main()
{

    return 0;
}