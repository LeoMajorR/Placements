#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int myAtoi(string s)
    {
        int i = 0;
        int sign = 1;
        int result = 0;
        if (s.length() == 0)
            return 0;
        while (s[i] == ' ')
            i++;
        if (s[i] == '-' || s[i] == '+') {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        while (s[i] >= '0' && s[i] <= '9') {
            if (result > INT_MAX / 10
                || (result == INT_MAX / 10
                    && s[i] - '0' > INT_MAX % 10)) {
                if (sign == 1)
                    return INT_MAX;
                else
                    return INT_MIN;
            }
            result = result * 10 + (s[i] - '0');
            i++;
        }
        return result * sign;
    }
};

