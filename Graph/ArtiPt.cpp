#include <bits/stdc++.h>
using namespace std;

// Articulation Point of a Graph
// Articulation Point : A vertex whose removal (or one of its descendants) makes the graph disconnected.

class Graph
{
    int V;
    list<int> *adj;

    void DFS(int v, bool visited[], int disc[], int low[], int time, int parent[], vector<int> &ap)
    {
        // Mark the current node as visited and print it
        visited[v] = true;
        disc[v] = low[v] = time++;

        // Recur for all the vertices adjacent to this vertex
        list<int>::iterator i;
        for (i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            // If this adjacent vertex is not visited yet, then recur for it
            if (!visited[*i])
            {
                parent[*i] = v;
                DFS(*i, visited, disc, low, time, parent, ap);

                // If the child returns low value as greater than discovery value of the current node, then update low value of current node
                low[v] = min(low[v], low[*i]);
                if (low[*i] >= disc[v])
                    ap.push_back(v);
            }

            // If an adjacent vertex is visited and not parent of current vertex, then update low value of current node
            else if (*i != parent[v])
                low[v] = min(low[v], disc[*i]);
        }
    }

public:
    Graph(int V)
    {
        this->V = V;
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

    vector<int> ArticulationPoint()
    {
        int disc[V] = {0};         // d[i] = discovery time of vertex i
        int low[V] = {0};          // low[i] = lowest vertex reachable from i
        int parent[V] = {-1};      // parent[i] = parent of i in DFS tree
        bool visited[V] = {false}; // visited[i] = is i visited?
        int time = 0;              // time = time of last vertex visited
        vector<int> ap;            // ap = articulation points

        for (int u = 0; u < V; u++)
        {
            if (!visited[u])
            {
                DFS(u, visited, disc, low, time, parent, ap);
            }
        }
    }
};

int main()
{
    Graph g(5);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(3, 4);

    vector<int> points = g.ArticulationPoint();
    for (int i = 0; i < points.size(); i++)
        cout << points[i] << " ";
    cout << endl;
    return 0;
}