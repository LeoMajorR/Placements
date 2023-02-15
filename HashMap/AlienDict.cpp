#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isAlienSorted(vector<string> &words, string order)
    {
        int m = order.size(), n = words.size();
        unordered_map<char, int> mp;
        for (int i = 0; i < m; i++)
            mp[order[i]] = i;
        for (int i = 0; i < n - 1; i++)
        {
            string s1 = words[i], s2 = words[i + 1];
            int l1 = s1.size(), l2 = s2.size();
            int j = 0;
            while (j < l1 && j < l2)
            {
                if (mp[s1[j]] < mp[s2[j]])
                    break;
                else if (mp[s1[j]] > mp[s2[j]])
                    return false;
                j++;
            }
            if (j == l2 && j < l1) // s2 is a prefix of s1
                return false;
        }
        return true;
    }
};

int main()
{
    Solution s;
    vector<string> words = {"apple", "app"};
    vector<string> words1 = {"hello", "leetcode"};
    string order = "abcdefghijklmnopqrstuvwxyz";
    string order1 = "hlabcdefgijkmnopqrstuvwxyz";
    // cout << s.isAlienSorted(words, order);
    cout << s.isAlienSorted(words1, order1);
    return 0;
}
