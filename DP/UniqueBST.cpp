#include <bits/stdc++.h>
using namespace std;


// apporach 1: recursion
// numTrees(n) = sum(numTrees(i - 1) * numTrees(n - i)) for i = 1 to n
int numTrees(int n)
{
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            dp[i] += dp[j - 1] * dp[i - j];
        }
    }
    return dp[n];
}