#include <bits/stdc++.h>
using namespace std;

// Minimum falling path sum
int minFallingPathSum(vector<vector<int>> &matrix)
{
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        dp[0][i] = matrix[0][i];
    for (int i = 1; i < m; i++)
    {
        // for each row
        for (int j = 0; j < n; j++)
        {
            dp[i][j] = dp[i - 1][j]; 
            if (j > 0) 
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
            if (j < n - 1) // if not the last column
                dp[i][j] = min(dp[i][j], dp[i - 1][j + 1]);
            dp[i][j] += matrix[i][j]; // add the value of the current cell
        }
    }
    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
        ans = min(ans, dp[m - 1][i]);
    return ans;
}