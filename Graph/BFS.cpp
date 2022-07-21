// Program to find shortest path bewteen two nodes in a graph

#include <bits/stdc++.h>
using namespace std;

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &vec)
{
    for (auto elem : vec)
    {
        os << elem << " ";
    }
    return os;
}

// adjacency list representation of graph
void add_edge(vector<vector<int>> &adj, int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool BFS(vector<vector<int>> &adj, int s, int d, int v, vector<int> &pred, vector<int> &dist)
{
    // mark all vertices as not visited
    vector<bool> visited(v, false);
    // create a queue, enqueue source vertex and mark source vertex as visited
    queue<int> q;

    // all entries of dist and pred are initialized to -1
    for (int i = 0; i < v; i++)
    {
        dist[i] = INT_MAX;
        pred[i] = -1;
    }
    visited[s] = true;
    dist[s] = 0;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = 0; i < adj[u].size(); i++)
        {
            if (visited[adj[u][i]] == false)
            {
                visited[adj[u][i]] = true;
                dist[adj[u][i]] = dist[u] + 1;
                pred[adj[u][i]] = u;
                q.push(adj[u][i]);

                if (adj[u][i] == d)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

void displayShortestPath(vector<vector<int>> &adj, int s, int d)
{
    int v = adj.size();
    vector<int> pred(v), dist(v);
    if (BFS(adj, s, d, v, pred, dist) == false)
    {
        cout << "No Path between given Points" << endl;
        return;
    }
    vector<int> path;
    int crawl = d;
    path.push_back(crawl); // push destination vertex to path[]

    while (pred[crawl] != -1) // while crawl is not source
    {
        path.push_back(pred[crawl]);
        crawl = pred[crawl];
    }

    cout << "Shortest Path between " << s << " and " << d << " is: ";
    for (int i = path.size() - 1; i >= 0; i--)
    {
        cout << path[i] << " ";
    }
    cout << endl;

    // display distance of all vertices from source
    cout << "Distance of all vertices from source: " << dist << endl;
}

int main()
{
    int vertics = 8;
    vector<vector<int>> adj(vertics);
    add_edge(adj, 0, 1);
    add_edge(adj, 0, 3);
    add_edge(adj, 1, 2);
    add_edge(adj, 3, 4);
    add_edge(adj, 3, 7);
    add_edge(adj, 4, 5);
    add_edge(adj, 4, 6);
    add_edge(adj, 4, 7);
    add_edge(adj, 5, 6);
    add_edge(adj, 6, 7);
    int source = 0;
    int destination = 7;
    // displayShortestPath(adj, source, destination);
    displayShortestPath(adj, 2, 5);
    return 0;
}