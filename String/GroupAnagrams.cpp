#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;
        for (auto s : strs)
        {
            string t = s;
            sort(t.begin(), t.end());
            mp[t].push_back(s);
        }
        for (auto p : mp)
        {
            ans.push_back(p.second);
        }
        return ans;
    }
};