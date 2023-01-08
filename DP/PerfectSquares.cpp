#include <bits/stdc++.h>
using namespace std;

template <typename T>
std::ostream & operator << (std::ostream & os, const std::vector<T> & vec)
{
    for(auto elem : vec)
    {
        os<<elem<< " ";
    }
    return os;
}

// approach : dp
//  d[i] = min(d[i], d[i - j * j] + 1)
int numSquares(int n)
{
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j * j <= i; j++)
        {
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }
    cout<<dp<<endl;
    return dp[n];
}

int main()
{
    cout<<numSquares(12)<<endl;
    cout<<numSquares(13)<<endl;
    return 0;
}