#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Detect cycle in Graph using BFS
 *
 * @tparam T
 */

class Graph
{
    int V;
    list<int> *adj;

public:
    Graph(int V)
    {
        this->V = V;
        adj = new list<int>[V];
    }
    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
        adj[w].push_back(v);
    }

    bool detectCycleUtil(int node, int parent, vector<bool> &visited)
    {
        visited[node] = true;
        queue<pair<int, int>> q;
        q.push(make_pair(node, parent));
        while (!q.empty())
        {
            pair<int, int> p = q.front();
            q.pop();
            int node = p.first;
            int parent = p.second;
            for (auto it : adj[node])
            {
                if (!visited[it])
                {
                    visited[it] = true;
                    q.push(make_pair(it, node));
                }
                else if (it != parent)
                {
                    cout << "Cycle detected at vertex : " << it << endl;
                    return true;
                }
            }
        }
        return false;
    }

    void detectCycle(int v)
    {
        vector<bool> visited(v, false);
        for (int i = 0; i < v; i++)
        {
            if (!visited[i])
            {
                if (detectCycleUtil(i, -1, visited))
                {
                    // cout << "Cycle detected" << endl;
                    return;
                }
            }
        }
    }
};

int main()
{
    int v = 8;
    Graph g(v);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(1, 4);
    g.addEdge(4, 5);
    g.addEdge(5, 6);
    g.addEdge(3, 6);
    g.addEdge(6, 7);
    g.detectCycle(v);
}