#include "bits/stdc++.h"
using namespace std;

bool canJump(vector<int> &nums)
{
    vector<bool> dp(nums.size(), false);
    dp[nums.size() - 1] = true;
    for (int idx = nums.size() - 2; idx >= 0; idx--)
    {
        bool a = false;
        for (int j = 1; j <= nums[idx]; ++j)
        {
            if (a == true)
                break;
            if ((idx + j) < nums.size())
                a = (a || dp[idx + j]);
        }
        dp[idx] = a;
    }
    return dp[0];
}

int main()
{

    return 0;
}