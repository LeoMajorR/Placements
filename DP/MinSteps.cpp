#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    /**
     * @algorithm: DP
     * 1. dp[i] = min(dp[j] + i / j) for all j < i and i % j == 0
     * 2. dp[1] = 0
     * 3. dp[i] = i for all i > 1
     * @param n: the number of keys
    */
    int minSteps(int n)
    {
        vector<int> dp(n + 1, 0);
        dp[1] = 0;
        // dp[i] = min(dp[j] + i / j) for all j < i and i % j == 0
        for (int i = 2; i <= n; i++) {
            dp[i] = i;
            for (int j = i - 1; j > 1; j--) {
                if (i % j == 0) {
                    dp[i] = min(dp[i], dp[j] + i / j);
                    break;
                }
            }
        }
        return dp[n];
    }
};

