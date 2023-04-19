#include <bits/stdc++.h>
using namespace std;

// Minimise the maximum of arrary
class Solution
{
public:
    /**
     * @Approach: DP
     * 1. Find the sum of array
     * 2. Find the subset of array whose sum is equal to sum/2
     * 3. Find the minimum of (sum - 2*subset_sum)
     *
     * @TimeComplexity: O(n*sum)
     * @SpaceComplexity: O(n*sum)
     *
     */
    int minimizeArrayValue(vector<int> &nums)
    {
        long long answer = 0, prefixSum = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            prefixSum += nums[i];
            answer = max(answer, (prefixSum + i) / (i + 1));
        }
        return answer;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {3, 7, 1, 6};
    cout << s.minimizeArrayValue(nums) << endl;
    return 0;
}