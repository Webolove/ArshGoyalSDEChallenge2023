#include "bits/stdc++.h"
using namespace std;

// You are not allowed to modify the array and perform in constant space complexity
int findDuplicate(vector<int> &nums)
{
    int fast = nums[0];
    int slow = nums[0];

    do
    {
        fast = nums[nums[fast]];
        slow = nums[slow];
    } while (slow != fast);

    fast = nums[0];
    while (slow != fast)
    {
        fast = nums[fast];
        slow = nums[slow];
    }
    return slow;
}

int main()
{

    return 0;
}