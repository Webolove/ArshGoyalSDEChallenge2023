#include "bits/stdc++.h"
using namespace std;

int count(int day, int buy, int k, vector<int> &prices, vector<vector<int>> &dp)
{
    if (buy >= k || day >= prices.size())
        return 0;
    if (dp[day][buy] != -1)
        return dp[day][buy];

    int profit;

    if (buy % 2 == 0)
    {
        int Buy = -prices[day] + count(day + 1, buy + 1, k, prices, dp);
        int NotBuy = count(day + 1, buy, k, prices, dp);
        profit = max(Buy, NotBuy);
    }
    else
    {
        int sell = prices[day] + count(day + 1, buy + 1, k, prices, dp);
        int Notsell = count(day + 1, buy, k, prices, dp);
        profit = max(sell, Notsell);
    }
    return dp[day][buy] = profit;
}


int maxProfit(int k, vector<int> &prices)
{
    vector<vector<int>> dp(prices.size(), vector<int>(2 * k, -1));
    return count(0, 0, 2 * k, prices, dp);
}

int main()
{

    return 0;
}