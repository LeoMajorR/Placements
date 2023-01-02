#include <bits/stdc++.h>
using namespace std;

class Solution {
public: 
    bool isPossible(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> graph(n); 
        for (auto& e : edges) {
            graph[e[0]-1].insert(e[1]-1); 
            graph[e[1]-1].insert(e[0]-1); 
        }
        vector<long> odd; 
        for (int i = 0; i < n; ++i) 
            if (graph[i].size() & 1) odd.push_back(i); 
        return odd.size() == 0 
            || odd.size() == 2 && any_of(graph.begin(), graph.end(), [&](auto& g) { return !g.count(odd[0]) && !g.count(odd[1]); })
            || odd.size() == 4 && (!graph[odd[0]].count(odd[1]) && !graph[odd[2]].count(odd[3]) || !graph[odd[0]].count(odd[2]) && !graph[odd[1]].count(odd[3]) || !graph[odd[0]].count(odd[3]) && !graph[odd[1]].count(odd[2]));
    }
};