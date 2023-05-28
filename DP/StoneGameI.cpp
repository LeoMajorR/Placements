#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool stoneGame(vector<int> &piles)
    {
        int n = piles.size();
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        for (int l = 1; l <= n; l++)
        {
            for (int i = 0, j = l - 1; j < n; i++, j++)
            {
                int parity = (i + j + n) % 2; // 0 for even, 1 for odd
                if (parity == 1)              // Alex's turn
                {
                    dp[i + 1][j + 1] = max(piles[i] + dp[i + 2][j + 1], piles[j] + dp[i + 1][j]);
                }
                else
                {
                    dp[i + 1][j + 1] = min(-piles[i] + dp[i + 2][j + 1], -piles[j] + dp[i + 1][j]);
                }
            }
        }
        return dp[1][n] > 0;
    }
};
