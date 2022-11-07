#include <bits/stdc++.h>
using namespace std;

//avg value of even integers div by 3
int avgCValue(vector<int> &nums)
{
    int sum = 0;
    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] % 2 == 0 && nums[i] % 3 == 0)
        {
            sum += nums[i];
            count++;
        }
    }
    if (count == 0)
        return 0;
    return sum / count;
}