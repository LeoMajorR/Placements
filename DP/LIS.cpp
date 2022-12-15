#include <bits/stdc++.h>
using namespace std;

template <typename T>
std::ostream & operator << (std::ostream & os, const std::vector<T> & vec)
{
    for(auto elem : vec)
    {
        os<<elem<< " ";
    }
    return os;
}

int LongestIncreasingSubsequence(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, 1);
    int ans = 1;
    cout<<"dp: "<<dp<<endl;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }
    cout<<"dp: "<<dp<<endl;
    return ans;
}

int main()
{
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << LongestIncreasingSubsequence(nums) << endl;
    return 0;
}