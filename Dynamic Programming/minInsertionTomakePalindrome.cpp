#include "bits/stdc++.h"
using namespace std;

unordered_map<int, unordered_map<int, int>> dp;
int lengthOfLongestPalindrome(int i, int j, string s)
{
    if (i > j)
        return 0;
    if (i == j)
        return 1;

    if (dp.find(i) != dp.end() && dp[i].find(j) != dp[i].end())
        return dp[i][j];

    if (s[i] == s[j])
        return dp[i][j] = 2 + lengthOfLongestPalindrome(i + 1, j - 1, s);
    return dp[i][j] = max(lengthOfLongestPalindrome(i + 1, j, s), lengthOfLongestPalindrome(i, j - 1, s));
}
int minInsertions(string s)
{
    vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
    for (int i = s.size() - 1; i >= 0; i--)
    {
        for (int j = 0; j < s.size(); ++j)
        {
            if (i > j)
                continue;
            if (i == j)
            {
                dp[i][j] = 1;
                continue;
            }

            if (s[i] == s[j])
                dp[i][j] = 2 + dp[i + 1][j - 1];
            else
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
    }
    return s.size() - dp[0][s.size() - 1];
}

int main()
{

    return 0;
}