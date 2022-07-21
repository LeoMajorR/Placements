
#include <bits/stdc++.h>
#include <fstream>
using namespace std;

int minDistance(vector<int> dist, vector<bool> sptSet)
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < dist.size(); v++)
    {
        if (sptSet[v] == false && dist[v] <= min)
        {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void printPath(vector<int> path, int s, int d)
{
    cout << "Path: ";
    for (int i = 0; i < path.size(); i++)
        cout << path[i] << " ";
    cout << endl;
    // cout << "Distance: " << dist[d] << endl;
}
void dijkstra(vector<vector<int>>, int src, int dest)
{
    int dist[V];
    bool visited[V];
    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = false;
    }
    dist[src] = 0;
    for (int i = 0; i < V; i++)
    {
        int u = minDistance(dist, visited);
        visited[u] = true;
        for (int v = 0; v < V; v++)
        {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    cout << "Distance: " << dist[dest] << endl;
    printPath(dist, src, dest);
}

int main()
{
    ifstream file;
    file.open("graph.txt");
    int m, n;
    file >> n;
    file >> m;
    vector<vector<int>> graph(m + 1, vector<int>(m + 1, 0));
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        file >> a >> b >> c;
        graph[a][b] = c;
    }
    while (true)
    {
        int dest;
        cout << "Enter destination: ";
        cin >> dest;
        dijkstra(graph, 0, dest);
    }
    file.close();
}