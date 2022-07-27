#include <bits/stdc++.h>
using namespace std;

/**
 * @brief The DijkstraAlgo class
 *
 * @param s The source vertex
 * @param d Distance array (Current length of shortest path from source to vertex v is d[v])
 * @param p Predecessor array
 */
vector<vector<pair<int, int>>> adj;

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &vec)
{
    for (auto elem : vec)
    {
        os << elem << " ";
    }
    return os;
}

void Dijkstra(int s, vector<int> &d, vector<int> &p)
{
    int n = adj.size();
    d.assign(n, INT_MAX);
    p.assign(n, -1);

    vector<bool> visited(n, false);
    d[s] = 0;

    for (int i = 0; i < n; i++)
    {
        int v = -1;
        for (int j = 0; j < n; j++)
        {
            if (!visited[j] && (v == -1 || d[j] < d[v]))
                v = j;
        }
        if (d[v] == INT_MAX)
            break;
        visited[v] = true;
        for (auto u : adj[v])
        {
            if (d[u.first] > d[v] + u.second)
            {
                d[u.first] = d[v] + u.second;
                p[u.first] = v;
            }
        }
    }
}

int main()
{
    int n = 9; // Number of vertices
    adj.resize(n);
    int m = 14; // Number of edges

    int s = 0; // Source vertex
    int t = 8; // Destination vertex
               /*u v w
                   0 1 4
                   0 7 8
                   1 7 11
                   1 2 8
                   2 8 2
                   8 6 6
                   7 8 7
                   7 6 1
                   6 5 2
                   2 5 4
                   2 3 7
                   3 5 14
                   3 4 9
                   4 5 10*/

    adj[0].push_back({1, 4});
    adj[0].push_back({7, 8});
    adj[1].push_back({7, 11});
    adj[1].push_back({2, 8});
    adj[2].push_back({8, 2});
    adj[8].push_back({6, 6});
    adj[7].push_back({8, 7});
    adj[7].push_back({6, 1});
    adj[6].push_back({5, 2});
    adj[2].push_back({5, 4});
    adj[2].push_back({3, 7});
    adj[3].push_back({5, 14});
    adj[3].push_back({4, 9});
    adj[4].push_back({5, 10});

    vector<int> d, p;
    Dijkstra(s, d, p);
    cout << "Distance from " << s << " to " << t << ": " << d[t] << endl;
    cout << "Path: ";
    vector<int> path;
    for (int i = t; i != -1; i = p[i])
        path.push_back(i);
    reverse(path.begin(), path.end());
    cout << path << endl;

    return 0;
}