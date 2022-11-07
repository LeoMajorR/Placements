#include <bits/stdc++.h>
using namespace std;

vector<int> maxSumCombinations(vector<int> &A, vector<int> &B, int k)
{
    vector<int> ans;
    priority_queue<pair<int, pair<int, int>>> pq;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int n = A.size();
    int m = B.size();
    pq.push({A[n - 1] + B[m - 1], {n - 1, m - 1}});
    set<pair<int, int>> s;
    s.insert({n - 1, m - 1});
    while (k--)
    {
        pair<int, pair<int, int>> p = pq.top(); // {sum, {i,j}}
        pq.pop();
        ans.push_back(p.first);
        int i = p.second.first;
        int j = p.second.second;
        if (s.find({i - 1, j}) == s.end())
        {
            pq.push({A[i - 1] + B[j], {i - 1, j}});
            s.insert({i - 1, j});
        }
        if (s.find({i, j - 1}) == s.end())
        {
            pq.push({A[i] + B[j - 1], {i, j - 1}});
            s.insert({i, j - 1});
        }
    }
    return ans;
}

int main()
{
    vector<int> A = {1, 4, 2, 3};
    vector<int> B = {2, 5, 1, 6};
    vector<int> ans = maxSumCombinations(A, B, 4);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    A = {68,35};
    B = {68,35};
    ans = maxSumCombinations(A, B, 1);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
}