#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxProduct(vector<int> &nums)
{
    int maxi = INT_MIN;
    int prod = 1;
    bool flag = false;
    int max_val = nums[0];
    for (int i = 0; i < nums.size(); ++i)
    {
        if (nums[i] != 0)
            flag = true;
        max_val = max(max_val, nums[i]);

        if (nums[i] == 0)
            prod = 1;
        else
        {
            prod *= nums[i];
            maxi = max(maxi, prod);
        }
    }
    if (!flag)
        return max_val;
    prod = 1;
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        if (nums[i] == 0)
            prod = 1;
        else
        {
            prod *= nums[i];
            maxi = max(maxi, prod);
        }
    }

    return max(maxi, max_val);
}

int main()
{

    return 0;
}