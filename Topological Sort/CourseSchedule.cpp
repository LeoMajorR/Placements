#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        for (auto &v : prerequisites)
        {
            adj[v[1]].push_back(v[0]);
            indegree[v[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }
        int count = 0; // count of nodes with indegree 0
        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                int curr = q.front();
                q.pop();
                count++;
                for (auto &v : adj[curr])
                {
                    indegree[v]--;
                    if (indegree[v] == 0)
                        q.push(v);
                }
            }
        }
        return count == numCourses;
    }
};
