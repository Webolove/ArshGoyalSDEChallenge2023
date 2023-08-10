#include "bits/stdc++.h"
using namespace std;

int CountWays(int idx, string s)
{
    if (idx < 0)
        return 0;
    if (idx == 0)
    {
        if (s[0] == '0')
            return 0;
        return 1;
    }

    int one_step_back = 0;
    if (s[idx - 1] != '0')
        one_step_back = CountWays(idx - 1, s);
    int two_step_back = 0;
    if ((idx - 2) >= 0)
    {
        string sm = "";
        sm += s[idx - 2];
        sm += s[idx - 1];
        int a = stoi(sm);
        if (a >= 10 && a <= 26)
            two_step_back = CountWays(idx - 2, s);
    }

    return (one_step_back + two_step_back);
}

int main()
{

    return 0;
}