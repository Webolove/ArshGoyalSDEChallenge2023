#include "bits/stdc++.h"
using namespace std;

vector<int> drow = {-1, 0, 1, 0};
vector<int> dcol = {0, -1, 0, 1};
bool searchWord(int row, int col, int idx, vector<vector<char>> &board, string word, vector<vector<bool>> &vis)
{
    if (idx >= word.size())
        return true;

    if (board[row][col] != word[idx])
        return false;
    else if (idx == word.size() - 1)
        return true;

    vis[row][col] = true;
    for (int i = 0; i < 4; ++i)
    {
        int newRow = row + drow[i];
        int newCol = col + dcol[i];
        if (newRow < 0 || newCol < 0 || newRow >= board.size() || newCol >= board[0].size())
            continue;

        if (!vis[newRow][newCol])
        {
            if (searchWord(newRow, newCol, idx + 1, board, word, vis))
                return true;
        }
    }
    vis[row][col] = false;
    return false;
}

bool exist(vector<vector<char>> &board, string word)
{
    int n = board.size();
    int m = board[0].size();
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (searchWord(i, j, 0, board, word, vis))
                return true;
        }
    }
    return false;
}

int main()
{

    return 0;
}