#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maxScore(vector<int> &nums1, vector<int> &nums2, int k)
    {
        int n = nums1.size();
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
            v.push_back({nums1[i], nums2[i]});
        sort(v.begin(), v.end(), [](pair<int, int> &a, pair<int, int> &b)
             { return a.second > b.second; }); // sort by nums2 in descending order
        priority_queue<int> pq;
        long long topKSum = 0;
        for (int i = 0; i < k; i++)
        {
            topKSum += v[i].first;
            pq.push(v[i].first);
        }
        long long ans = topKSum * v[k - 1].second; // ans = sum of top k elements in nums1 * min element in nums2
        for (int i = k; i < n; i++)
        {
            topKSum += v[i].first;
            pq.pop();
            pq.push(v[i].first);
            ans = max(ans, topKSum * v[i].second);
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums1 = {2, 1, 14, 12};
    vector<int> nums2 = {11, 7, 13, 6};
    int k = 3;
    cout << s.maxScore(nums1, nums2, k) << endl;
    return 0;
}