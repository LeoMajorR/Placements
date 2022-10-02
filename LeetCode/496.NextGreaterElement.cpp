#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> ans;
    stack<int> s;
    unordered_map<int, int> m;
    for (auto n : nums2)
    {
        while (!s.empty() && s.top() < n)
        {
            m[s.top()] = n;
            s.pop();
        }
        s.push(n);
    }
    for (auto n : nums1)
        ans.push_back(m.count(n) ? m[n] : -1);
    return ans;
}

int main()
{
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    auto ans = nextGreaterElement(nums1, nums2);
    for (auto n : ans)
        cout << n << " ";
    cout << endl;
    return 0;
}