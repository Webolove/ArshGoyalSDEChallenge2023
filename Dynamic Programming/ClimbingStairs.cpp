#include <iostream>
using namespace std;

int climbStairs(int n)
{
    int temp_1 = 1, temp_2 = 0;
    int temp = 0;
    for (int i = 1; i <= n; ++i)
    {
        temp = temp_1 + temp_2;
        temp_2 = temp_1;
        temp_1 = temp;
    }
    return temp;
}

int main()
{

    return 0;
}