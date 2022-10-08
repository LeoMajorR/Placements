/*
 * @lc app=leetcode id=1312 lang=cpp
 *
 * [1312] Minimum Insertion Steps to Make a String Palindrome
 */

// @lc code=start
class Solution
{
public:
    int minInsertions(string s)
    {
        string s1 = s;
        reverse(s.begin(), s.end());
        string s2 = s;
        int n = s1.size();
        vector<int> prev(n + 1, 0), cur(n + 1, 0);

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    cur[j] = prev[j - 1] + 1;
                }
                else
                {
                    cur[j] = max(prev[j], cur[j - 1]);
                }
            }
            swap(prev, cur);
        }
        return n - prev[n];
    }
};
// @lc code=end
