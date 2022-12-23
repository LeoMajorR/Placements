#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void dfs2(vector<vector<int>> &graph, int cur, int pre, vector<int> &count, vector<int> &res)
    {
        for (auto &next : graph[cur]) {
            if (next == pre) continue;
            res[next] = res[cur] - count[next] + count.size() - count[next];
            dfs2(graph, next, cur, count, res);
        }
    }

    void dfs(vector<vector<int>> &graph, int cur, int pre, vector<int> &count, vector<int> &res)
    {
        for (auto &next : graph[cur]) {
            if (next == pre) continue;
            dfs(graph, next, cur, count, res);
            count[cur] += count[next];
            res[cur] += res[next] + count[next];
        }
    }

  vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> graph(n);
        for (auto &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        vector<int> count(n, 1);
        vector<int> res(n, 0);
        dfs(graph, 0, -1, count, res);
        dfs2(graph, 0, -1, count, res);
        return res;
    }
};

