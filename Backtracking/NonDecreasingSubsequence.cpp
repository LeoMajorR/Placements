#include <bits/stdc++.h>
using namespace std;

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &vec)
{
    for (auto elem : vec)
    {
        os << elem << " ";
    }
    return os;
}

class Solution
{
public:
    void findSubsequence(vector<int> &nums, int index, vector<int> &temp, vector<vector<int>> &res)
    {
        // base case
        // if we have reached the end of the array, then we have found a subsequence
        if (index == nums.size())
        {
            res.push_back(temp);
            return;
        }
        // recursive case
        // if the current element is greater than or equal to the last element of the current subsequence
        if (temp.empty() || nums[index] >= temp.back())
        {
            temp.push_back(nums[index]);
            findSubsequence(nums, index + 1, temp, res); //
            temp.pop_back();                             // backtrack
        }
        // if the current element is not equal to the last element of the current subsequence
        // then we can skip the current element
        if (temp.empty() || nums[index] != temp.back())
        {
            findSubsequence(nums, index + 1, temp, res);
        }
    }

    // all possible non-decreasing subsequences
    vector<vector<int>> findSubsequence(vector<int> &nums)
    {
        vector<vector<int>> res;
        vector<int> temp;
        findSubsequence(nums, 0, temp, res);
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {4, 6, 7, 7};
    vector<vector<int>> res = s.findSubsequence(nums);
    for (auto vec : res)
    {
        cout << vec << endl;
    }
}
