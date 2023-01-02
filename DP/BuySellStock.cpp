#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  /**
   * @method : Buy Sell Stocks with cooldown
   * 
   * Algorithm:
   * 1. if n<=1, return 0
   * 2. if n==2, return max(0, prices[1]-prices[0])
   * 3. create a 2D vector of size n+2, 2
   * 4. dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i-1])
   * 5. dp[i][1] = max(dp[i-1][1], dp[i-2][0] - prices[i-1])
   * 6. return dp[n][0]
   * 
  */
  int maxProfit(vector<int> &prices)
  {
    int n = prices.size();
    if(n <= 1) return 0;
    vector<int> s0(n, 0); // no stock
    vector<int> s1(n, 0); // have stock
    vector<int> s2(n, 0); // cooldown
    s0[0] = 0; //dont have any stock
    s1[0] = -prices[0]; //have stock
    s2[0] = INT_MIN; //cooldown

    for(int i=1;i<n;i++)
    {
        s0[i] = max(s0[i-1], s2[i-1]);
        s1[i] = max(s1[i-1], s0[i-1]-prices[i]);
        s2[i] = s1[i-1]+prices[i];
    }
    return max(s0[n-1], s2[n-1]);
  }
};

int main()
{
    Solution s;
    vector<int> prices = {1,2,3,0,2};
    cout << s.maxProfit(prices) << endl;
    return 0;
}

