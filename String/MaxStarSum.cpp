#include <bits/stdc++.h>
using namespace std;

int maxStarSum(vector<int> &vals, vector<vector<int>> &edges, int k)
{
    unordered_map<int, vector<pair<int, int>>> adj;
    for(int i=0;i<edges.size();i++)
    {
        adj[edges[i][0]].push_back({edges[i][1], vals[edges[i][1]]});
        adj[edges[i][1]].push_back({edges[i][0], vals[edges[i][0]]});
    }
    int ans= INT_MIN;
    for(auto it: adj)
    {
        int sum=0;
        // add max k values
        sort(it.second.begin(), it.second.end(), [](pair<int, int> &a, pair<int, int> &b){
            return a.second>b.second;
        });
        int temp = it.second.size();
        int i = 0;
        while(i<k && i<temp)
        {
            if(it.second[i].second>0)
                sum+=it.second[i].second
            i++;
        }
        sum+=vals[it.first];
        ans=max(ans, sum);
    }
    if(adj.size()==0)
        return *max_element(vals.begin(), vals.end());
    return ans;
}

int main()
{
    //vals =  [1,2,3,4,10,-10,-20]
    //edges = [[0,1],[1,2],[1,3],[3,4],[3,5],[3,6]]
    //k = 2
    vector<int> vals = {1,2,3,4,10,-10,-20};
    vector<vector<int>> edges = {{0,1},{1,2},{1,3},{3,4},{3,5},{3,6}};
    int k = 2;
    // cout << maxStarSum(vals, edges, k);
    vector<int> vals1 = {1,-8,0};
    vector<vector<int>> edges1 = {{0,1},{1,2}};
    int k1 = 2;
    cout << maxStarSum(vals1, edges1, k1);
}