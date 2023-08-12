#include "bits/stdc++.h"
using namespace std;

void sortColors(vector<int> &nums)
{
    int first = 0, last = nums.size() - 1, mid = 0;
    while (mid <= last)
    {
        if (nums[mid] == 0)
        {
            int temp = nums[first];
            nums[first] = nums[mid];
            nums[mid] = temp;
            first++;
            mid++;
        }
        else if (nums[mid] == 2)
        {
            int temp = nums[last];
            nums[last] = nums[mid];
            nums[mid] = temp;
            last--;
        }
        else
            mid++;
    }
}

int main()
{

    return 0;
}