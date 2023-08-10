#include <iostream>
#include <vector>
using namespace std;

int coinChange(vector<int> &coins, int amount)
{
    vector<int> front(amount + 1, 0), curr(amount + 1, 0);
    for (int i = 0; i <= amount; ++i)
        front[i] = 1e9;

    for (int idx = 1; idx <= coins.size(); ++idx)
    {
        for (int val = 1; val <= amount; ++val)
        {
            int notpick = front[val];
            int pick = 1e9;
            if (val - coins[idx - 1] >= 0)
                pick = 1 + curr[val - coins[idx - 1]];
            curr[val] = min(pick, notpick);
        }
        front = curr;
    }
    int a = front[amount];
    if (a >= 1e9)
        return -1;
    return a;
}

int main()
{

    return 0;
}