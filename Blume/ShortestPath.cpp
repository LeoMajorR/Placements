#include <bits/stdc++.h>
using namespace std;

int minCost(int n, vector<vector<int>> &trains)
{
    vector<vector<pair<int, int>>> graph(n + 1);
    for (auto &train : trains)
    {
        graph[train[0]].push_back({train[1], train[2]});
        graph[train[1]].push_back({train[0], train[2]});
    }
    vector<int> dist(n + 1, INT_MAX);
    dist[1] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    while (!pq.empty())
    {
        auto curr = pq.top();
        pq.pop();
        int currNode = curr.second;
        int currDist = curr.first;
        if (currDist > dist[currNode])
            continue;
        for (auto &neighbour : graph[currNode])
        {
            int nextNode = neighbour.first;
            int nextDist = neighbour.second;
            if (dist[nextNode] > dist[currNode] + nextDist)
            {
                dist[nextNode] = dist[currNode] + nextDist;
                pq.push({dist[nextNode], nextNode});
            }
        }
    }
    return dist[n] == INT_MAX ? -1 : dist[n];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        // n : no of cities
        // m : no of trains
        int m, n;
        cin >> n >> m;
        vector<vector<int>> trains(m, vector<int>(3));
        for (int i = 0; i < m; i++)
        {
            cin >> trains[i][0] >> trains[i][1] >> trains[i][2];
        }
        cout << "Cost :" << minCost(n, trains) << endl;
    }
    return 0;
}