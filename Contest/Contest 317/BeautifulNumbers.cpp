#include <bits/stdc++.h>
using namespace std;


// given n fin x such that sum of digits of n+x is less than equal to target
long long makeIntegerBeautiful(long long n, int target)
{
    long long x = 0;
    long long sum = 0;
    long long temp = n;
    while (temp > 0)
    {
        sum += temp % 10;
        temp /= 10;
    }
    while (sum > target)
    {
        x++;
        sum = 0;
        temp = n + x;
        while (temp > 0)
        {
            sum += temp % 10;
            temp /= 10;
        }
    }
    return x;
}