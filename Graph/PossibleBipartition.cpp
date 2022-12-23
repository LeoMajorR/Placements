#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int, vector<int>> graph;

        vector<int> color(n + 1, 0);

        for(int i = 0; i < dislikes.size(); i++) {
            graph[dislikes[i][0]].push_back(dislikes[i][1]);
            graph[dislikes[i][1]].push_back(dislikes[i][0]);
        }

        //BFS
        for(int i=1;i<=n;i++)
        {
            if(!color[i])
            {
                queue<int> q;
                q.push(i);  
                color[i]=1;
                while(!q.empty())
                {
                    int curr=q.front();
                    q.pop();

                    //check for all the neighbours
                    for(auto x:graph[curr])
                    {
                        //if the neighbour is of same color then return false
                        if(color[x]==color[curr])
                            return false;
                        //if the neighbour is not colored then color it with opposite color
                        if(!color[x])
                        {
                            color[x]=-color[curr];
                            q.push(x);
                        }
                    }
                }
            }
        }
        return true;
    }
};