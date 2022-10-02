/*
 * @lc app=leetcode id=303 lang=cpp
 *
 * [303] Range Sum Query - Immutable
 */

// @lc code=start
class NumArray
{
    vector<int> sum;

public:
    NumArray(vector<int> &nums)
    {
        for (auto n : nums)
        {
            if (sum.empty())
                sum.push_back(n);
            else
                sum.push_back(sum.back() + n);
        }
    }

    int sumRange(int left, int right)
    {
        if (left == 0)
            return sum[right];
        return sum[right] - sum[left - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end
