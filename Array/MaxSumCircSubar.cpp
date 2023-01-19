#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int maxSum = INT_MIN;
        int minSum = INT_MAX;
        int sum = 0;
        int totalSum = 0;
        for(int i=0;i<n;i++){
            sum += nums[i];
            maxSum = max(maxSum, sum);
            if(sum<0) sum = 0;
            totalSum += nums[i];
            nums[i] = -nums[i];
        }
        sum = 0;
        for(int i=0;i<n;i++){
            sum += nums[i];
            minSum = min(minSum, sum);
            if(sum<0) sum = 0;
        }
        if(totalSum == minSum) return maxSum;
        return max(maxSum, totalSum-minSum);
    }
};

int main()
{
    Solution s;
    vector<int> arr = {-3,-2,-3};
    cout<<s.maxSubarraySumCircular(arr);
    return 0;
}