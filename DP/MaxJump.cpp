#include <bits/stdc++.h>
using namespace std;

template <typename T>
std::ostream & operator << (std::ostream & os, const std::vector<T> & vec)
{
    for(auto elem : vec)
    {
        os<<elem<< " ";
    }
    return os;
}

// given pos of stones, initially at first stone
// cost of jumping from i to j is |stones[i]-stones[j]|
// return the max length of jump
int macJump(vector<int> &stones)
{
    int n = stones.size();
    vector<int> dp(n, 0);
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            int cost = abs(stones[i]-stones[j]);
            if(dp[j] >= cost)
            {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }
    return dp[n-1];
}


int maxJump(vector<int> &stones)
{
    int n = stones.size();
    vector<vector<int> > dp(n, vector<int>(n, INT_MAX));
    dp[0][0] = 0;
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            int cost = abs(stones[i]-stones[j]);
            for(int k=0; k<n; k++)
            {
                if(dp[j][k] != INT_MAX)
                {
                    dp[i][j] = min(dp[i][j], dp[j][k]+cost);
                }
            }
        }
    }
    int ans = INT_MAX;
    for(int i=0; i<n; i++)
    {
        ans = min(ans, dp[n-1][i]);
    }
    return ans;
}

 int main()
 {
    vector<int> stones = {0,2,5,6,7};
    cout << maxJump(stones);
 }