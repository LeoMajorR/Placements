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

    bool checkInclusion(string s1, string s2)
    {
        if (s1.size() > s2.size())
            return false;

        int s1_count[26] = {0};
        int s2_count[26] = {0};

        for (int i = 0; i < s1.length(); i++)
        {
            s1_count[s1[i] - 'a']++;
            s2_count[s2[i] - 'a']++;
        }
        int windowStart = 0;
        int windowEnd = s1.length();

        while (windowEnd < s2.length())
        {
            if (matches(s1_count, s2_count))
                return true;

            s2_count[s2[windowEnd] - 'a']++;
            s2_count[s2[windowStart] - 'a']--;
            windowStart++;
            windowEnd++;
        }
        if (matches(s1_count, s2_count))
            return true;
        else
            return false;
    }
};