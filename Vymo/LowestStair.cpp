#include <bits/stdc++.h>
using namespace std;
// jumps = [1,-4,-2,3]
// output = 6

// find the lowest stair such that monkey remains on the stairs after each jump
int lowestStair(vector<int> jumps)
{
    int n = jumps.size();
    int sum = 0;
    int minSum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += jumps[i];
        minSum = min(minSum, sum);
    }
    return 1 - minSum;
}
// int lowestStartingStair(vector<int> &jumps)
// {
//     int n = jumps.size();
//     int dp[n + 1] = {0};
//     dp[n] = 0;
//     for (int i = n - 1; i >= 0; i--)
//     {
//         dp[i] = INT_MAX;
//         for (int j = 1; j <= jumps[i] && i + j <= n; j++)
//         {
//             if (dp[i + j] != INT_MAX)
//             {
//                 dp[i] = min(dp[i], dp[i + j] + 1);
//             }
//         }
//     }
//     return dp[0];
// }

int main()
{
    vector<int> jumps = {-5, 4, -2, 3, 1, -1, -6, -1, 0, -5};
    cout << lowestStair(jumps) << endl;
}