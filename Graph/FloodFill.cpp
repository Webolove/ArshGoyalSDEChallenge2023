#include "bits/stdc++.h"
using namespace std;

void dfs(int i, int j, vector<vector<int>> &img, int newCol, int init_col, vector<vector<bool>> &visited)
{
    img[i][j] = newCol;
    visited[i][j] = true;
    if ((i - 1) >= 0)
    {
        if (img[i - 1][j] == init_col && !visited[i - 1][j])
            dfs(i - 1, j, img, newCol, init_col, visited);
    }
    if ((i + 1) < img.size())
    {
        if (img[i + 1][j] == init_col && !visited[i + 1][j])
            dfs(i + 1, j, img, newCol, init_col, visited);
    }
    if ((j - 1) >= 0)
    {
        if (img[i][j - 1] == init_col && !visited[i][j - 1])
            dfs(i, j - 1, img, newCol, init_col, visited);
    }
    if ((j + 1) < img[0].size())
    {
        if (img[i][j + 1] == init_col && !visited[i][j + 1])
            dfs(i, j + 1, img, newCol, init_col, visited);
    }
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    int init_color = image[sr][sc];
    vector<vector<bool>> visited(image.size(), vector<bool>(image[0].size(), false));
    dfs(sr, sc, image, color, init_color, visited);
    return image;
}

int main()
{

    return 0;
}