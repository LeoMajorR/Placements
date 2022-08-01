#include <bits/stdc++.h>
using namespace std;

struct edge
{
    int u, v, w;
};

void createGraph(int u, int v, int w, vector<edge> &graph)
{
    edge e;
    e.u = u;
    e.v = v;
    e.w = w;
    graph.push_back(e);
}
void bellmanFord(int n, vector<edge> &graph, int src)
{
    int dist[n + 1];
    for (int i = 0; i < n + 1; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < graph.size(); j++)
        {
            int u = graph[j].u;
            int v = graph[j].v;
            int w = graph[j].w;
            if (dist[u] != INT_MAX && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    }
    for (int i = 0; i < graph.size(); i++)
    {
        int u = graph[i].u;
        int v = graph[i].v;
        int w = graph[i].w;
        if (dist[u] != INT_MAX && dist[u] + w < dist[v])
            cout << "Graph contains negative weight cycle" << endl;
    }

    // print dist array
    for (int i = 1; i < n + 1; i++)
        cout << dist[i] << " ";
}

int main()
{
    int v, e; // v-number of vertices, e-number of edges
    v = 5;
    e = 7;
    /**
     * (u,v,w)
     * (1,2,6)
     * (1,3,5)
     * (2,3,-2)
     * (2,4,-1)
     * (3,4,4)
     * (4,5,3)
     */
    vector<edge> graph;
    createGraph(1, 2, 6, graph);
    createGraph(1, 3, 5, graph);
    createGraph(3, 2, -2, graph);
    createGraph(2, 4, -1, graph);
    createGraph(3, 4, 4, graph);
    createGraph(4, 5, 3, graph);
    createGraph(3, 5, 3, graph);
    int s = 1; // source vertex
    // time for execution of bellmanFord() function
    bellmanFord(v, graph, s);
    return 0;
}