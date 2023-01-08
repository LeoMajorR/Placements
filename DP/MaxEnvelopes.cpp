#include <bits/stdc++.h>
using namespace std;

template <typename T>
std::ostream & operator << (std::ostream & os, const std::vector<T> & vec)
{
    for(auto elem : vec)
    {
        os<<elem<< " ";
    }
    return os;
}

class Solution {
    public:
    int macEnvelopes(vector<vector<int>> &envelopes)
    {
        int n = envelopes.size();
        if (n == 0) return 0;
        sort(envelopes.begin(), envelopes.end(), [](vector<int> &a, vector<int> &b) {
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
        }); // sort by width, if width is same, sort by height in descending order
        vector<int> dp;
        for(int i=0;i<n;i++)
        {
            int h = envelopes[i][1];
            auto it = lower_bound(dp.begin(), dp.end(), h); 
            if (it == dp.end()) // if h is greater than all elements in dp, push it to dp
            {
                dp.push_back(h);
            }
            else // if h is smaller than some element in dp, replace it with h
            {
                *it = h;
            }
        }
        return dp.size();
    }
};

int main()
{
    vector<vector<int>> envelopes = {{5,4},{6,4},{6,7},{2,3}};
    Solution s;
    cout << s.macEnvelopes(envelopes) << endl;
    return 0;
}
