#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findLeastNumberOfUniqueInts(vector<int> &arr, int k)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < arr.size(); i++)
        {
            mp[arr[i]]++;
        }
        vector<int> v;
        for (auto it : mp)
        {
            v.push_back(it.second);
        }
        sort(v.begin(), v.end());
        int i = 0;
        while (k > 0)
        {
            if (k >= v[i])
            {
                k -= v[i];
                i++;
            }
            else
            {
                break;
            }
        }
        return v.size() - i;
    }
};

int main()
{
    Solution s;
    vector<int> v = {4, 3, 1, 1, 3, 3, 2};
    cout << s.findLeastNumberOfUniqueInts(v, 3);
    return 0;
}