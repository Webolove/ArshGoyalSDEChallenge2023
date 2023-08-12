#include "bits/stdc++.h"
using namespace std;

int maxProfit(vector<int> &prices)
{
    int price = prices[0];
    int maxprofit = 0;
    for (int i = 1; i < prices.size(); i++)
    {
        price = min(price, prices[i]);
        maxprofit = max(maxprofit, prices[i] - price);
    }
    return maxprofit;
}

int main()
{

    return 0;
}