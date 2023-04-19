#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        if (needle == "")
            return 0;
        int n = haystack.size();
        int m = needle.size();
        for (int i = 0; i < n; i++)
        {
            if (haystack[i] == needle[0])
            {
                int j = 0;
                while (j < m && i + j < n && haystack[i + j] == needle[j])
                {
                    j++;
                }
                if (j == m)
                    return i;
            }
        }
        return -1;
        }
};
