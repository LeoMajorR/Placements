#include <bits/stdc++.h>
using namespace std;

/**
 *  @brief: Longest Square Streak
 *  @description: Given array of integers. A subsequence of the array is called a square streak if:
 * 1. The subsequence has at least 2 elements
 * 2. After sorting the subsequence, each element is square of the previous element
*/


// int longestSquareStreak(vector<int> &nums)
// {
//     int n = nums.size();
//     vector<int> dp(n, 0);
//     sort(nums.begin(), nums.end()); 
//     for(int i=0; i<n; i++)
//     {
//         dp[i] = 1;
//         for(int j=0; j<i; j++)
//         {
//             if(nums[i] == nums[j]*nums[j])
//             {
//                 dp[i] = max(dp[i], dp[j]+1);
//             }
//         }
//     }
//     int ans = 0;
//     for(int i=0; i<n; i++)
//     {
//         ans = max(ans, dp[i]);
//     }
//     if(ans == 1)
//         return -1;
//     return ans;
// }

int longestSquareStreak(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<int> dp(n, 0);
    
    int ans = 0;
    for(int i=0; i<n; i++)
    {
        ans = max(ans, dp[i]);
    }
    if(ans == 1)
        return -1;
    return ans;
}

int main()
{
    vector<int> nums1 = {4,3,6,16,8,2};
    vector<int> nums2 = {2,3,5,6,7};
    vector<int> nums3 = {2,4};
    cout<<longestSquareStreak(nums1)<<endl;
    cout<<longestSquareStreak(nums2)<<endl;
    cout<<longestSquareStreak(nums3)<<endl;
}