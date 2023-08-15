#include "bits/stdc++.h"
using namespace std;

int maxProfit(vector<int> &price)
{
    vector<int> front(2, 0), curr(2, 0);
    for (int day = price.size() - 1; day >= 0; day--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            int profit = 0;
            if (buy == 1) // You are allowed to buy
            {
                int buy = -price[day] + front[0];
                int notbuy = front[1];
                profit = max(buy, notbuy);
            }
            else
            {
                int sell = price[day] + front[1];
                int notSell = front[0];
                profit = max(sell, notSell);
            }
            curr[buy] = profit;
        }
        front = curr;
    }
    return front[1];
}

int main()
{

    return 0;
}