#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfArrays(stringg s, int k)
    {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[n] = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == '0')
                continue;
            long long num = 0;
            for (int j = i; j < n; j++)
            {
                num = num * 10 + (s[j] - '0');
                if (num > k)
                    break;
                dp[i] = (dp[i] + dp[j + 1]) % 1000000007;
            }
        }
        return dp[0];
    }
};
