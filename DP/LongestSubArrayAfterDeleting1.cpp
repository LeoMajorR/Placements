#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Longest Subarray of 1's After Deleting One Element
    /**
     * @Intution: We can use two pointers to keep track of the longest subarray of 1's. We can use a count variable to keep track of the number of 0's in the subarray. When we encounter a 0, we can increment the count. If the count is greater than 1, we can move the left pointer to the right until the count is 1. We can keep track of the maximum length of the subarray.
     * @Approach: Sliding Window
     * @Time Complexity: O(n)
     * @Space Complexity: O(1)
     */
    int longestSubarray(vector<int> &nums)
    {
        int n = nums.size();
        int left = 0, right = 0;
        int count = 0;
        int maxLen = 0;
        while (right < n)
        {
            if (nums[right] == 0)
            {
                count++;
            }
            while (count > 1)
            {
                if (nums[left] == 0)
                {
                    count--;
                }
                left++;
            }
            maxLen = max(maxLen, right - left);
            right++;
        }
        return maxLen;
    }
};

int main()
{
    Solution a;
    vector<int> in = {1, 1, 0, 1};
    cout << a.longestSubarray(in) << endl;
    return 0;
}