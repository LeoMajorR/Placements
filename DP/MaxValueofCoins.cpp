#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /**
     * @param piles:
     */
    int maxValueOfCoins(vector<vector<int>> &piles, int k)
    {
        int n = piles.size();
        int m = piles[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            dp[i][0] = piles[i][0];
        }
        for (int j = 1; j < m; j++)
        {
            for (int i = 0; i < n; i++)
            {
                int left = (i == 0) ? 0 : dp[i - 1][j - 1];
                int right = (i == n - 1) ? 0 : dp[i + 1][j - 1];
                dp[i][j] = max(left, right) + piles[i][j];
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, dp[i][m - 1]);
        }
        return ans;
    }
};

int main()
{
    // piles = [ [ 1, 100, 3 ], [ 7, 8, 9 ] ], k = 2
    vector<vector<int>> piles = {{1, 100, 3}, {7, 8, 9}};
    int k = 2;
    Solution s;
    cout << s.maxValueOfCoins(piles, k) << endl;
}
