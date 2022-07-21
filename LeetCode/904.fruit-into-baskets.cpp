/*
 * @lc app=leetcode id=904 lang=cpp
 *
 * [904] Fruit Into Baskets
 */

// @lc code=start
class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        int n = fruits.size();
        // base case
        if (n == 1)
            return 1;
        int max_count = 0;
        int start = 0, end = 0;
        unordered_map<int, int> mp;
        while (end < n)
        {
            mp[fruits[end]]++;
            if (mp.size() <= 2)
            {
                max_count = max(max_count, end - start + 1);
                end++;
            }
            else if (mp.size() > 2)
            {
                while (mp.size() > 2)
                {
                    mp[fruits[start]]--;
                    if (mp[fruits[start]] == 0)
                        mp.erase(fruits[start]);
                    start++;
                }
                end++;
            }
        }
        return max_count;
    }
};
// @lc code=end
