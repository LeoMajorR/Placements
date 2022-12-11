#include <bits/stdc++.h>
using namespace std;

// Delete the element with the greatest value from each row. If multiple such elements exist, delete any of them.
// add the maximum of deleted elements to answer 
int deleteGreatestValue(vector<vector<int>> &grid)
{
    for(int i=0; i<grid.size(); i++)
    {
        sort(grid[i].begin(), grid[i].end());
    }
    int ans = 0;
    int temp;
    for(int i=grid[0].size()-1; i>=0; i--)
    {
        temp = 0;
        for(int j=0; j<grid.size(); j++)
        {
            temp = max(temp, grid[j][i]);
        }
        ans += temp;
    }
    return ans;
}

int main()
{
    //[[9,81],[33,17]]
    vector<vector<int>> grid = {{9,81},{33,17}};
    cout<<deleteGreatestValue(grid)<<endl;
}