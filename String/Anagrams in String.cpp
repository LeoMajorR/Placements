#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool matches(int s1_data[], int s2_data[])
    {
        for (int i = 0; i < 26; i++)
        {
            if (s1_data[i] != s2_data[i])
                return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> ans;
        if (s.length() < p.length())
            return ans;

        int s1_data[26] = {0};
        int s2_data[26] = {0};

        for (int i = 0; i < p.length(); i++)
        {
            s1_data[s[i] - 'a']++;
            s2_data[p[i] - 'a']++;
        }

        int windowStart = 0;
        int windowEnd = p.length();

        while (windowEnd < s.length())
        {
            if (matches(s1_data, s2_data))
                ans.push_back(windowStart);

            s1_data[s[windowEnd] - 'a']++;
            s1_data[s[windowStart] - 'a']--;
            windowStart++;
            windowEnd++;
        }
        if (matches(s1_data, s2_data))
            ans.push_back(windowStart);
        return ans;
    }
};