#include <bits/stdc++.h>
using namespace std;

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &vec)
{
    for (auto elem : vec)
    {
        os << elem << " ";
    }
    return os;
}

// sum of elements at end along all paths from 0,0 to m,n
int pathDivByK(vector<vector<int>> &grid, int k)
{
    vector<int> sum;
    int m = grid.size();
    int n = grid[0].size();
    int dp[m][n];
    dp[0][0] = grid[0][0];
    for (int i = 1; i < m; i++)
    {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }
    for (int j = 1; j < n; j++)
    {
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    }
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + grid[i][j];
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int p = i; p < m; p++)
            {
                for (int q = j; q < n; q++)
                {
                    int s = dp[p][q];
                    if (i > 0)
                    {
                        s -= dp[i - 1][q];
                    }
                    if (j > 0)
                    {
                        s -= dp[p][j - 1];
                    }
                    if (i > 0 && j > 0)
                    {
                        s += dp[i - 1][j - 1];
                    }
                    if (s % k == 0)
                    {
                        sum.push_back(s);
                    }
                }
            }
        }
    }
    cout << "sum: " << sum << endl;
    return sum.size();
}

int main()
{
    vector<vector<int>> grid = {{5, 2, 4}, {3, 0, 5}, {0, 7, 2}};
    int k = 3;
    cout << pathDivByK(grid, k) << endl;
    return 0;
}