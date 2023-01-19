#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int reverse(int x)
    {
        int rev = 0;
        while(x>0)
        {
            rev = rev*10 + x%10;
            x /= 10;
        }
        return rev;
    }

    int countNicePairs(vector<int> nums)
    {
        int count=0;
        unordered_map<int, int> m;
        for(int i = 0; i<nums.size(); i++)
        {
            int rev = reverse(nums[i]);
            int diff = nums[i]-rev;
            count += m[diff];
            m[diff]++;
        }
        // return count % 1000000007;
        return count;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {42,11,1,97};
    cout<<s.countNicePairs(nums);
    return 0;
}

