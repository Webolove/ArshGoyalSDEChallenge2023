#include "bits/stdc++.h"
using namespace std;

int uniquePaths(int m, int n)
{
    if (m == n && n == 1)
        return 1;

    int N = (m + n - 2);
    int X = (m - 1);

    double res = 1;
    for (int i = 1; i <= X; ++i)
        res = res * (N - X + i) / i;
    return res;
}

int main()
{

    return 0;
}