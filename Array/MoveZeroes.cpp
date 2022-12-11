#include <bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int> &nums)
{
    int n = nums.size();
    int i = 0, j = 0;
    while (j < n)
    {
        if (nums[j] != 0)
        {
            swap(nums[i], nums[j]);
            i++;
        }
        j++;
    }
}

int main()
{
    vector<int> nums = {0, 1, 0, 3, 12};
    moveZeroes(nums);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
}