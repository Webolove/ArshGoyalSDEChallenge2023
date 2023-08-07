#include "bits/stdc++.h"
using namespace std;

// Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
// Output: [1,2,2,3,5,6]

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int a = 0;
    for (int i = m; i < m + n; ++i)
    {
        nums1[i] = nums2[a];
        a++;
    }
    sort(nums1.begin(), nums1.end());
}

int main()
{

    return 0;
}