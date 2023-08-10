#include "bits/stdc++.h"
using namespace std;

int longestCommonSubstr(string s1, string s2, int n, int m)
{
    vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));
    int max_len = 0;
    for (int i = 1; i <= s1.size(); ++i)
    {
        for (int j = 1; j <= s2.size(); ++j)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                max_len = max(max_len, dp[i][j]);
            }
        }
    }
    return max_len;
}

int main()
{

    return 0;
}