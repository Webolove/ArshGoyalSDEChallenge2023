#include "bits/stdc++.h"
using namespace std;

int findLength(vector<int> &nums1, vector<int> &nums2)
{
    int l1 = nums1.size(), l2 = nums2.size();
    vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));
    int max_len = 0;
    for (int i = 1; i <= l1; ++i)
    {
        for (int j = 1; j <= l2; ++j)
        {
            if (nums1[i - 1] == nums2[j - 1])
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