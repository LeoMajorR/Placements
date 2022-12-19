#include <bits/stdc++.h>
using namespace std;

vector<int> dailyTemperature(vector<int> &temperatures)
{
    int n = temperatures.size();
    vector<int> ans(n, 0);
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        // if stack is not empty and current element is greater than top of stack
        while (!s.empty() && temperatures[i] > temperatures[s.top()])
        {
            ans[s.top()] = i - s.top(); // store the difference of index
            s.pop();
        }
        s.push(i);
    }
    return ans;
}

int main()
{
    vector<int> arr = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> ans = dailyTemperature(arr);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
}