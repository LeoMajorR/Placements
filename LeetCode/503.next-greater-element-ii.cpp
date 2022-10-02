/*
 * @lc app=leetcode id=503 lang=cpp
 *
 * [503] Next Greater Element II
 */

// @lc code=start
class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        vector<int> res(nums.size(), -1);
        stack<int> s;
        unordered_map<int, int> m;

        for (auto n : nums)
        {
            while (!s.empty() && s.top() < n)
            {
                m[s.top()] = n;
                s.pop();
            }
            s.push(n);
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (m.count(nums[i]))
                res[i] = m[nums[i]];
        }

        return res;
    }
};
// @lc code=end
