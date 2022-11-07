#include <bits/stdc++.h>
using namespace std;

//return creator, id with highest view count
vector<vector<string>> mostPopularCreator(vector<string> &creators, vector<string> &ids, vector<int> &views)
{
    vector<vector<string>> ans;
    unordered_map<string, int> m;
    for (int i = 0; i < creators.size(); i++)
    {
        m[creators[i]] += views[i];
    }
    // creator with highest view count
    int max = 0;
    for (auto i : m)
    {
        if (i.second > max)
            max = i.second;
    }
    // return creator, id with highest view count
    // if same creator has multiple ids with highest view count return lexigraphically smallest id
    for (int i = 0; i < creators.size(); i++)
    {
        if (m[creators[i]] == max)
        {
            ans.push_back({creators[i], ids[i]});
        }
    }
    // remove duplicate creators
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    return ans;
}