#include <bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n, 1);
    int left = 1, right = 1;
    for (int i = 0; i < n; i++)
    {
        ans[i] *= left;
        left *= nums[i];
        ans[n - i - 1] *= right;
        right *= nums[n - i - 1];
    }
    return ans;
}

int main()
{
    vector<int> arr={1,2,3,4};
    vector<int> ans=productExceptSelf(arr);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
}