#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int profitableSchemes(int n, int minProfit, vector<int> &group, vector<int> &profit)
    {
        int mod = 1e9 + 7;
        int m = group.size();
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(minProfit + 1, 0)));
        dp[0][0][0] = 1;
        for (int i = 1; i <= m; i++)
        {
            int members = group[i - 1];
            int earn = profit[i - 1];
            for (int j = 0; j <= n; j++)
            {
                for (int k = 0; k <= minProfit; k++)
                {
                    dp[i][j][k] = dp[i - 1][j][k];
                    if (j >= members)
                    {
                        dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j - members][max(0, k - earn)]) % mod;
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i <= n; i++)
        {
            ans = (ans + dp[m][i][minProfit]) % mod;
        }
        return ans;
    }
};
