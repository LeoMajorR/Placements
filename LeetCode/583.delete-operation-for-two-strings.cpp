/*
 * @lc app=leetcode id=583 lang=cpp
 *
 * [583] Delete Operation for Two Strings
 */

// @lc code=start
class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int m = word1.size(), n = word2.size();
        vector<int> prev(n + 1, 0), cur(n + 1, 0);
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (word1[i - 1] == word2[j - 1])
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
        return m + n - 2 * prev[n];
    }
};
// @lc code=end
