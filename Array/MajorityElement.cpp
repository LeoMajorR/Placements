#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> &nums)
{
    //moore's voting algorithm
    int count = 0;
    int candidate = -1;
    for (int i = 0; i < nums.size(); i++)
    {
        if (count == 0)
        {
            candidate = nums[i];
        }
        if (nums[i] == candidate)
        {
            count++;
        }
        else
        {
            count--;
        }
    }
    return candidate;
}