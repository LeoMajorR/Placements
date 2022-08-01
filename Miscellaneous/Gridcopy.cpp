#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Given rectangular grid of m*n dimension, made up of square tiles 1*1.
 * Find minimum square tile required to cover all the grid cells.
 *
 * @param m number of rows in grid
 * @param n number of columns in grid
 */

int dp[100][100] = {INT_MAX};

int minimumSquares(int m, int n)
{
    // already square
    if (m == n)
        return 1;
    if (m < 0 || n < 0)
        return 0;
    if (dp[m][n] != INT_MAX)
        return dp[m][n];

    // Rectangle is cut horizontally and vertically into two parts and minimum value is called in recursive manner.

    // finding cut point along horizontal axis with minimum value
    for (int i = 1; i < m; i++)
        dp[m][n] = min(dp[m][n], minimumSquares(i, n) + minimumSquares(m - i, n));

    for (int i = 1; i <= n / 2; i++)
        dp[m][n] = min(dp[m][n], minimumSquares(m, i) + minimumSquares(m, n - i));
    return dp[m][n];
}

int main()
{
    int m, n;
    m = 18, n = 16;
    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= n; j++)
            dp[i][j] = INT_MAX;
    cout << minimumSquares(m, n) << endl;
    return 0;
}