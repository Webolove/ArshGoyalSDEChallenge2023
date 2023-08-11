#include "bits/stdc++.h"
using namespace std;

inline int count_bits(int n)
{
    int count = 0;
    while (n != 0)
    {
        n = n & (n - 1);
        count++;
    }
    return count;
}
vector<int> countBits(int n)
{
    vector<int> ans(n + 1, 0);
    for (int i = 1; i <= n; ++i)
        ans[i] = count_bits(i);
    return ans;
}

int main()
{

    return 0;
}