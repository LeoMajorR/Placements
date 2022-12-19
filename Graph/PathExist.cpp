#include <bits/stdc++.h>
using namespace std;

bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
{
    unordered_map<int, vector<int>> graph;
    for(auto edge : edges)
    {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }
    
    queue<int> q;
    q.push(source);
    vector<bool> visited(n, false);
    visited[source] = true;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        if(node == destination)
            return true;
        for(auto neighbour : graph[node])
        {
            if(!visited[neighbour])
            {
                q.push(neighbour);
                visited[neighbour] = true;
            }
        }
    }
    return false;
}