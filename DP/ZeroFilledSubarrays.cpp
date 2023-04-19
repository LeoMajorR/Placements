#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /**
     * @Approach: Prefix Sum + Hashing
     * 1. We will use prefix sum to find the sum of subarray from index i to j.
     * 2. If the sum of subarray from index i to j is 0, then the sum of subarray from index 0 to j is equal to the sum of subarray from index 0 to i-1.
     * 3. So, we will use hashing to store the frequency of each prefix sum.
     * 4. If the prefix sum is 0, then we will increment the answer by 1.
     * 5. If the prefix sum is not 0, then we will increment the answer by the frequency of the prefix sum.
     * 6. We will also increment the frequency of the prefix sum by 1.
     * 7. We will return the answer.
     *
     * Time Complexity: O(N)
     * Space Complexity: O(N)
     * array contains negative numbers
     */
    long long zeroFilledSubarray(vector<int> &nums)
    {
        }
};

int main()
{
    Solution obj;
    vector<int> nums = {1, 0, 0, 1, 0, 0, 1, 1};
    cout << obj.zeroFilledSubarray(nums) << endl;
}
