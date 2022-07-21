#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
            return false;
        int s_data[26] = {0};
        int t_data[26] = {0};
        for (int i = 0; i < s.length(); i++)
        {
            s_data[s[i] - 'a']++;
            t_data[t[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++)
        {
            if (s_data[i] != t_data[i])
                return false;
        }
        return true;
    }
};