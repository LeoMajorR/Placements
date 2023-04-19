#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minNumberOfSemesters(int n, vector<vector<int>> &dependencies)
    {
        vector<int> indegree(n + 1, 0);
        vector<vector<int>> adj(n + 1);
        for (auto &v : dependencies)
        {
            adj[v[0]].push_back(v[1]);
            indegree[v[1]]++;
        }
        queue<int> q;
        for (int i = 1; i <= n; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }
        int sem = 0;
        while (!q.empty())
        {
            int size = q.size();
            sem++;
            while (size--)
            {
                int curr = q.front();
                q.pop();
                for (auto &v : adj[curr])
                {
                    indegree[v]--;
                    if (indegree[v] == 0)
                        q.push(v);
                }
            }
        }
        return sem;
    }
};

int main()
{
    int n = 4;
    vector<vector<int>> dependencies = {{2, 1}, {3, 1}, {1, 4}};
    Solution s;
    cout << s.minNumberOfSemesters(n, dependencies) << endl;
    return 0;
}
