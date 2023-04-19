#include <bits/stdc++.h>
using namespace std;

/**
 * @Approach: Topological Sort
 * @Time complexity: O(V+E)
 * @Space complexity: O(V+E)
 */
class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> indegree(numCourses, 0); // indegree of each node
        vector<vector<int>> adj(numCourses); // adjacency list to store the graph
        for (auto &v : prerequisites)
        {
            adj[v[1]].push_back(v[0]); // directed edge from v[1] to v[0]
            indegree[v[0]]++;
        }
        queue<int> q; // queue to store nodes with indegree 0
        for (int i = 0; i < numCourses; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }
        vector<int> ans;
        // BFS
        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                int curr = q.front();
                q.pop();
                ans.push_back(curr);
                for (auto &v : adj[curr])
                {
                    indegree[v]--;
                    if (indegree[v] == 0)
                        q.push(v);
                }
            }
        }
        if (ans.size() != numCourses)
            return {};
        return ans;
    }
};
