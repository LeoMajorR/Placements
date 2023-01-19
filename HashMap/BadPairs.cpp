#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    /**
     *j-i!=nums[j] 
    */
    long long countBadPairs(vector<int> &nums)
    {
        long long count;
        unordered_map<int, int> m;  
        for(int i=0; i<nums.size(); i++)
        {
            m[nums[i]-i]++;
            if(m[nums[i]-i]>1)
            {
                count += m[nums[i]-i]-1;
            }
        }
        return nums.size()*(nums.size()-1)/2 - count;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {1, 2,3,4};
    cout<<s.countBadPairs(nums);
    return 0;
}

