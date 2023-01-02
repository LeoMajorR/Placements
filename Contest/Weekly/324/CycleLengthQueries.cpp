#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>> &queries)
    {
        vector<int> ans;
        vector<unordered_set<int>> graph(n);
        for (auto &e : queries) {
            if (e[0] == 1) {
                graph[e[1] - 1].insert(e[2] - 1);
                graph[e[2] - 1].insert(e[1] - 1);
            } else {
                vector<int> odd;
                for (int i = 0; i < n; ++i)
                    if (graph[i].size() & 1)
                        odd.push_back(i);
                ans.push_back(odd.size() == 0 || odd.size() == 2 && any_of(graph.begin(), graph.end(), [&](auto &g) { return !g.count(odd[0]) && !g.count(odd[1]); }) || odd.size() == 4 && (!graph[odd[0]].count(odd[1]) && !graph[odd[2]].count(odd[3]) || !graph[odd[0]].count(odd[2]) && !graph[odd[1]].count(odd[3]) || !graph[odd[0]].count(odd[3]) && !graph[odd[1]].count(odd[2])));
            }
        }
        return ans;
    }
};

int main()
{
    
}
