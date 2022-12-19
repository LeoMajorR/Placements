#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int start=0, end=0;
        for(int i=0; i<n; ++i)
        {
            dp[i][i] = true;
            if(i<n-1 && s[i]==s[i+1])
            {
                dp[i][i+1] = true;
                start = i;
                end = i+1;
            }
        }
        for(int len=3; len<=n; ++len)
        {
            for(int i=0; i<n-len+1; ++i)
            {
                int j = i+len-1;
                if(s[i]==s[j] && dp[i+1][j-1])
                {
                    dp[i][j] = true;
                    start = i;
                    end = j;
                }
            }
        }
        return s.substr(start, end-start+1);
    }
};