#include <bits/stdc++.h>
using namespace std;

string addString(string s1, string s2)
{
    string s3 = "";
    int carry = 0;
    int i = s1.length() - 1;
    int j = s2.length() - 1;
    while (i >= 0 || j >= 0 || carry)
    {
        int sum = 0;
        if (i >= 0)
        {
            sum += (s1[i] - '0');
            i--;
        }
        if (j >= 0)
        {
            sum += (s2[j] - '0');
            j--;
        }
        sum += carry;
        carry = sum / 10;
        sum = sum % 10;
        s3 += to_string(sum);
    }
    reverse(s3.begin(), s3.end());
    return s3;
}