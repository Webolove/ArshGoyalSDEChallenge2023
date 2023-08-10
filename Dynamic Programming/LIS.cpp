#include "bits/stdc++.h"
using namespace std;

int lengthOfLIS(vector<int> &nums)
{
    vector<int> res;
    res.push_back(nums[0]);
    for (int i = 1; i < nums.size(); ++i)
    {
        if (nums[i] > res[res.size() - 1])
            res.push_back(nums[i]);
        else
        {
            vector<int>::iterator it;
            it = lower_bound(res.begin(), res.end(), nums[i]);
            int idx = it - res.begin();
            res[idx] = nums[i];
        }
    }
    return res.size();
}

int main()
{

    return 0;
}