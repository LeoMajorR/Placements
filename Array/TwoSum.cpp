#include <bits/stdc++.h>
using namespace std;

// for sorted array
int twoSum(vector<int> arr, int x)
{
    int n = arr.size();
    int i = 0, j = n - 1;
    while (i < j)
    {
        if (arr[i] + arr[j] == x)
            return 1;
        else if (arr[i] + arr[j] < x)
            i++;
        else
            j--;
    }
    return 0;
}

vector<int> twoSum(vector<int> ans, int x)
{
    int n = ans.size();
    vector<int> ans;
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
    {
        if (s.find(x - ans[i]) != s.end())
        {
            ans.push_back(x - ans[i]);
            ans.push_back(ans[i]);
            return ans;
        }
        s.insert(ans[i]);
    }
}

// for unsorted array
vector<int> twoSum(vector<int> arr, int x)
{
    vector<int> ans;
    int n = arr.size();
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        if (mp.find(x - arr[i]) != mp.end())
        {
            ans.push_back(mp[x - arr[i]]);
            ans.push_back(i);
            return ans;
        }
        mp[arr[i]] = i;
    }
    return ans;
}