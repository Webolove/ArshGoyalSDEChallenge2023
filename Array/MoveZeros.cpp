#include "bits/stdc++.h"
using namespace std;

void moveZeroes(vector<int> &nums)
{
    int idx = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (nums[i] != 0)
            nums[idx++] = nums[i];
    }
    while (idx < nums.size())
        nums[idx++] = 0;
}

int main()
{

    return 0;
}