#include <bits/stdc++.h>
using namespace std;

// Maximum in Generated Array
int getMaximumGenerated(int n)
{
    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (i & 1)
            dp[i] = dp[i / 2] + dp[i / 2 + 1];
        else
            dp[i] = dp[i / 2];
    }
    return *max_element(dp.begin(), dp.end());
}

int main()
{
    int n = 0;
    cout << getMaximumGenerated(n);
    cout << getMaximumGenerated(3);
    return 0;
}