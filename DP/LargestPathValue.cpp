#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largestPathValue(string colors, vector<vector<int>> &edges)
    {
        int n = colors.size();
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        for (auto &edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }
        vector<int> dp(n, 0);
        int ans = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            dp[node] = 1;
            for (auto &it : adj[node])
            {
                if (colors[it] == colors[node])
                    dp[it] = max(dp[it], dp[node] + 1);
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
            ans = max(ans, dp[node]);
        }
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] != 0)
                return -1;
        }
        return ans;
    }
};
