#include <bits/stdc++.h>
using namespace std;

// Perform BFS to find connected components in directed graph

// Graph Class -> Adjacency list representation
class Graph
{
    int V;
    list<int> *adj; // Pointer to array containing adjacency list

    // BFS Util Function
    void BFSutil(int v, bool visited[])
    {
        // mark current node as visited and print it
        visited[v] = true;
        cout << v << " ";

        // get all adjacent vertices of v
        list<int>::iterator i;
        for (i = adj[v].begin(); i != adj[v].end(); ++i)
            if (!visited[*i])
                BFSutil(*i, visited);
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
    void connectedComponents()
    {
        bool *visited = new bool[V];

        // mark all as unvisited
        for (int i = 0; i < V; i++)
            visited[i] = false;

        // iterate through unvisited vertices and perform BFS
        for (int i = 0; i < V; i++)
        {
            if (visited[i] == false)
            {
                BFSutil(i, visited); // all vertices connected to i
                cout << endl;
            }
        }
        delete[] visited;
    }
};

int main()
{
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    g.addEdge(4, 5);

    cout << "Following are connected components in given graph \n";
    g.connectedComponents();
}