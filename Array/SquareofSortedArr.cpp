#include <bits/stdc++.h>
using namespace std;

vector<int> sortedSquares(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n);
    int i = 0, j = n - 1, k = n - 1;
    while (i <= j)
    {
        if (nums[i] * nums[i] > nums[j] * nums[j])
        {
            ans[k--] = nums[i] * nums[i];
            i++;
        }
        else
        {
            ans[k--] = nums[j] * nums[j];
            j--;
        }
    }
    return ans; 
}