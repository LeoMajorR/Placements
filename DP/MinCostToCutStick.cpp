#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /**
     * @Algorithm: DP
     * 1. Sort the cuts
     * 2. Add 0 and n to the cuts
     * 3. Now we have to find the min cost to cut the stick from 0 to n
     * 4. We can cut the stick at any of the cuts
     * 5. So we can divide the stick into two parts and find the min cost to cut the left and right part
     * 6. We can do this for all the cuts and find the min cost
     * 7. We can use DP to store the min cost for each cut
     * 8. dp[i][j] = min cost to cut the stick from i to j
     * 9. dp[i][j] = min(dp[i][k] + dp[k][j]) + (cuts[j] - cuts[i])
     * 10. We can use bottom up approach to find the min cost
     * 11. Time Complexity: O(n^3)
     */
    int minCost(int n, vector<int> &cuts)
    {
        int m = cuts.size();
        sort(cuts.begin(), cuts.end());
        vector<int> newCuts;
        newCuts.push_back(0);
        for (int i = 0; i < m; i++)
            newCuts.push_back(cuts[i]);
        newCuts.push_back(n);
        m = newCuts.size();
        vector<vector<int>> dp(m, vector<int>(m, 0));
        for (int i = 0; i < m - 1; i++)
            dp[i][i + 1] = 0;
        for (int l = 3; l <= m; l++)
        {
            for (int i = 0; i <= m - l; i++)
            {
                int j = i + l - 1;
                dp[i][j] = INT_MAX;
                for (int k = i + 1; k < j; k++)
                {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                }
                dp[i][j] += newCuts[j] - newCuts[i];
            }
        }
        return dp[0][m - 1];
    }
};

int main()
{
    Solution s;
    vector<int> cuts = {1, 3, 4, 5};
    cout << s.minCost(7, cuts);
}
