#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    // count Digits in num that divides num
    int countDigits(int num)
    {
        int count = 0;
        int temp = num;
        while (temp > 0) {
            int digit = temp % 10;
            if (digit != 0 && num % digit == 0)
                count++;
            temp /= 10;
        }
        return count;
    }
};