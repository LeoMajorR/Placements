#include <bits/stdc++.h>
using namespace std;

// given n nodes of a graph
// 3 types of queries
// 1 X1 : add new node with value X1
// 2 x1 x2 : two nodes x1 and x2 are connected
// 3 X3 : print no of connected components with power strictly greater than X3
// power of a node is product of all distinct prime factors of its value
// power of group is product of power of all nodes in that group
int main()
{
    int n, q;
    // n: no of nodes
    // q: no of queries

    cin >> n >> q;

    vector<int> nodes(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> nodes[i];

    //create a graph of nodes
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        graph[]
    }


    vector<vector<int>> queries;
    for (int i = 0; i < q; i++)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int x;
            cin >> x;
            queries.push_back({t, x});
        }
        else if (t == 2)
        {
            int x, y;
            cin >> x >> y;
            queries.push_back({t, x, y});
        }
        else
        {
            int x;
            cin >> x;
            queries.push_back({t, x});
        }
    }
    for (int i = 0; i < queries.size(); i++)
    {
        if (queries[i][0] == 1)
        {
            nodes.push_back(queries[i][1]);
            graph.push_back({});
        }
        else if (queries[i][0] == 2)
        {
            graph[queries[i][1]].push_back(nodes.size());
            graph[nodes.size()].push_back(queries[i][1]);
            graph[queries[i][2]].push_back(nodes.size());
            graph[nodes.size()].push_back(queries[i][2]);
            nodes.push_back(1);
        }
        else
        {
            int ans = 0;
            vector<bool> visited(nodes.size(), false);
            for (int j = 1; j < nodes.size(); j++)
            {
                if (!visited[j])
                {
                    int power = 1;
                    queue<int> q;
                    q.push(j);
                    visited[j] = true;
                    while (!q.empty())
                    {
                        int curr = q.front();
                        q.pop();
                        int temp = nodes[curr];
                        for (int k = 2; k <= sqrt(temp); k++)
                        {
                            int count = 0;
                            while (temp % k == 0)
                            {
                                temp /= k;
                                count++;
                            }
                            if (count % 2 == 1)
                                power *= k;
                        }
                        if (temp > 1)
                            power *= temp;
                        for (int k = 0; k < graph[curr].size(); k++)
                        {
                            if (!visited[graph[curr][k]])
                            {
                                q.push(graph[curr][k]);
                                visited[graph[curr][k]] = true;
                            }
                        }
                    }
                    if (power > queries[i][1])
                        ans++;
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}