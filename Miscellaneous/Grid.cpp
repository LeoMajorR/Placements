#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Given rectangular grid of m*n dimension, made up of square tiles 1*1.
 * Find minimum square tile required to cover all the grid cells.
 *
 * @param m number of rows in grid
 * @param n number of columns in grid
 */

const int MAX = 10000;
int dp[MAX][MAX];

int minimumMoves(int m, int n)
{
    int horizontal_min = INT_MAX, vertical_min = INT_MAX;

    // special case: if (m,n) = (11, 13) or (13, 11) then return 6
    if (m == 11 && n == 11)
        return 6;
    if (n == 13 && m == 13)
        return 6;

    // already square
    if (m == n)
        return 1;
    if (dp[m][n])
        return dp[m][n];

    // Rectangle is cut horizontally and vertically into two parts and minimum value is called in recursive manner.

    // finding cut point along horizontal axis with minimum value
    for (int i = 1; i <= m / 2; i++)
        horizontal_min = min(minimumMoves(i, n) + minimumMoves(m - i, n), horizontal_min);

    for (int i = 1; i <= n / 2; i++)
        vertical_min = min(minimumMoves(m, i) + minimumMoves(m, n - i), vertical_min);

    dp[m][n] = min(horizontal_min, vertical_min);
    return dp[m][n];
}

int main()
{
    int m, n;
    m = 18, n = 16;
    cout << minimumMoves(m, n) << endl;
    return 0;
}