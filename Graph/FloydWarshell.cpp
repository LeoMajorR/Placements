#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> floydWarshell(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<vector<int>> dist(n, vector<int>(n, 0));

    // distance matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i == j)
                dist[i][j] = 0;
            else if (graph[i][j] == 0)
                dist[i][j] = INT_MAX;
            else
                dist[i][j] = graph[i][j];
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (dist[i][k] < INT_MAX && dist[k][j] < INT_MAX)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    return dist;
}

int main()
{
    vector<vector<int>> graph = {{0, 2, 0, 0, 0, 0, 0},
                                 {0, 0, -4, 0, 1, 0, 0},
                                 {0, 0, 0, 2, 0, 0, 0},
                                 {0, 3, 0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0, 0, 4},
                                 {0, 0, 0, 0, 0, 0, 0}};
    vector<vector<int>> dist = floydWarshell(graph);
    for (int i = 0; i < dist.size(); i++)
    {
        for (int j = 0; j < dist[i].size(); j++)
        {
            if (dist[i][j] == INT_MAX)
                continue;
            else if (dist[i][j] == 0)
                cout << "(" << i << "," << j << ") = "
                     << "No Path" << endl;
            else
                cout << "(" << i << "," << j << ") = " << dist[i][j] << endl;
        }
    }
}