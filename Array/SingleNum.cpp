#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int> &nums)
{
    int ones = 0, twos = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        ones = (ones ^ nums[i]) & ~twos; // if ones is 1, then twos is 0
        twos = (twos ^ nums[i]) & ~ones; // if twos is 1, then ones is 0
    }
    return ones;
}

int main()
{
    vector<int> nums = {2, 2, 3, 2, 4, 4, 4};
    cout << singleNumber(nums) << endl;
    return 0;
}