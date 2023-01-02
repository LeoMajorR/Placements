#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  // 
  int numTilings(int n)
  {
    int mod = 1e9 + 7;
    int dp[n + 1]={0};
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++) {
      dp[i] = (2 * dp[i - 1] % mod + dp[i - 3]) % mod; // 2*dp[i-1] is for 2*1, dp[i-3] is for 1*2
    }
    return dp[n];
  }
};


int main()
{
  Solution s;
  int n = 3;
  cout << s.numTilings(n) << endl;
  return 0;
}
