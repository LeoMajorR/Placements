#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Find the bridges in a graph
 * @time O(m+n) m : number of edges, n : number of vertices
 * @space O(m)
 */

class Graph
{
    int v;
    list<int> *adj;

public:
    Graph(int V)
    {
        this->v = V;
        adj = new list<int>[V];
    }
    ~Graph()
    {
        delete[] adj;
    }
    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
        adj[w].push_back(v);
    }

    void dfs(int node, int parent, vector<int> &visited, vector<int> &t_in, vector<int> &low, int &time)
    {
        visited[node] = 1;
        t_in[node] = low[node] = time++;
        list<int>::iterator it;
        for (it = adj[node].begin(); it != adj[node].end(); it++)
        {
            // if node is parent of *it, then ignore it
            if (*it == parent)
                continue;

            // if *it is not visited, then recurse on it
            if (visited[*it] == 0)
            {
                dfs(*it, node, visited, t_in, low, time);
                // update low value of node (while backtracking)
                low[node] = min(low[node], low[*it]);
                if (low[*it] > t_in[node])
                    cout << "Bridge: " << node << " " << *it << endl;
            }
            // if *it is visited, then update low value of node (while backtracking)
            else
            {
                low[node] = min(low[node], t_in[*it]);
            }
        }
    }

    void findBridges(int V)
    {
        vector<int> visited(V, 0);
        vector<int> t_insertion(V, -1); // time of insertion (entry time of node)
        vector<int> low_time(V, -1);    // lowest time (minimum of t_insertion)
        int timer = 0;
        for (int i = 0; i < v; i++)
        {
            if (visited[i] == 0)
            {
                dfs(i, -1, visited, t_insertion, low_time, timer);
            }
        }
    }
    void displayGraph()
    {
        cout << "----------------------------------------------------" << endl;
        cout << "Graph: " << endl;
        for (int i = 0; i < v; i++)
        {
            cout << i << ": ";
            list<int>::iterator it;
            for (it = adj[i].begin(); it != adj[i].end(); it++)
                cout << *it << " ";
            cout << endl;
        }
        cout << "----------------------------------------------------" << endl;
    }
};

int main()
{
    Graph g(12);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(0, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(5, 6);
    g.addEdge(6, 7);
    g.addEdge(7, 8);
    g.addEdge(5, 8);
    g.addEdge(7, 9);
    g.addEdge(9, 10);
    g.addEdge(10, 11);
    g.addEdge(9, 11);
    g.findBridges(12);
    g.displayGraph();
    return 0;
}