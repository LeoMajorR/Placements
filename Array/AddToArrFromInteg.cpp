#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> addToArrayFrom(vector<int> &num, int k)
    {
        int n = num.size();
        int carry = k;
        for (int i = n - 1; i >= 0; i--)
        {
            int sum = num[i] + carry;
            num[i] = sum % 10;
            carry = sum / 10;
        }
        while (carry)
        {
            num.insert(num.begin(), carry % 10);
            carry /= 10;
        }
        return num;
    }
};
