#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

void sortOnFrequency(string &input)
{
    int n = (int)input[0];
    vector<int> arr;
    for (int i = 1; i < input.length(); i++)
    {
        arr[i] = (int)input[i];
    }
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[arr[i]]++;
    sort(arr.begin(), arr.end(), [&](int a, int b)
         {
        if (mp[a] == mp[b])
            return a < b;
        return mp[a] < mp[b]; });
    string ans = "";
    for (int i = 0; i < n; i++)
        ans += (char)arr[i];
    input = ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> ans = sortOnFrequency(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}