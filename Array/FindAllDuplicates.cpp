#include "bits/stdc++.h"
using namespace std;

vector<int> findDuplicates(vector<int> &nums)
{
    vector<int> ans;

    // TC : O(n*log(n))     SC : O(1)
    // sort(nums.begin(), nums.end());
    // for(int i = 0; i < nums.size() - 1; ++i){
    //     if(nums[i] == nums[i + 1])
    //         ans.push_back(nums[i]);
    // }

    // TC : O(n)    SC : O(n)
    // unordered_map<int, int> freq;
    // for(int i = 0; i < nums.size(); ++i){
    //     freq[nums[i]]++;
    //     if(freq[nums[i]] > 1)
    //         ans.push_back(nums[i]);
    // }

    // TC : (nearly) O(n)   SC : O(1)
    set<int> st;
    for (int i = 0; i < nums.size(); ++i)
    {
        if (nums[i] != i + 1)
        {
            int idx = nums[i] - 1;
            if (nums[idx] == nums[i])
                st.insert(nums[i]);
            else
            {
                swap(nums[idx], nums[i]);
                i -= 1;
            }
        }
    }
    for (auto it : st)
        ans.push_back(it);

    return ans;
}

int main()
{

    return 0;
}