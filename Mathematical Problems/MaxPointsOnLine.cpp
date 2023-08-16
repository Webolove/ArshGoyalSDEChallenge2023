#include "bits/stdc++.h"
using namespace std;

int maxPoints(vector<vector<int>> &points)
{
    if (points.size() <= 2)
        return points.size();

    unordered_map<int, int> freq; // slope freq;
    int ans = 2;
    for (int i = 0; i < points.size() - 1; ++i)
    {
        for (int j = i + 1; j < points.size(); ++j)
        {
            int y2 = points[j][1];
            int y1 = points[i][1];
            int x2 = points[j][0];
            int x1 = points[i][0];

            int dx = x2 - x1;
            int dy = y2 - y1;

            int count = 2;
            for (int k = j + 1; k < points.size(); ++k)
            {
                int y = points[k][1];
                int x = points[k][0];

                int dx_ = x - x2;
                int dy_ = y - y2;
                if (dx * dy_ == dy * dx_)
                {
                    count++;
                    ans = max(ans, count);
                }
            }
            cout << endl;
        }
    }
    return ans;
}

int main()
{

    return 0;
}