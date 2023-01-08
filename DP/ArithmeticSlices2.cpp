#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    // no of all arithmetic subsequences of nums 
    /**
     * @algorithm: DP
     * 1.   dp[i][diff] = number of arithmetic subsequences ending at index i with difference diff
     * 2.   dp[i][diff] = sum of dp[j][diff] for all j < i and nums[j] - nums[i] == diff
     * 3.   res = sum of all dp[i][diff]
     * @time: O(n^2)
     * @space: O(n^2)
    */
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 3) return 0;
        int res = 0;
        vector<unordered_map<long, int>> dp(n);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                long diff = (long)nums[i] - nums[j];
                int sum = 0;
                if (dp[j].find(diff) != dp[j].end()) {
                    sum = dp[j][diff];
                }
                dp[i][diff] += sum + 1;
                res += sum;
            }
        }
        return res;  
    }
};

int main()
{
    Solution s;
    vector<int> nums = {2,4,6,8,10};
    vector<int> nums1 = {7,7,7,7,7};
    cout << s.numberOfArithmeticSlices(nums) << endl;
    cout << s.numberOfArithmeticSlices(nums1) << endl;
    return 0;   
}
