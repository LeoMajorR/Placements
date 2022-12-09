#include <bits/stdc++.h>
using namespace std;
// arr[i] : vaccine count of type i
// n : number of dealers
// m : number of vaccine types
// disttribute vaccine to each dealer such that each dealer such that each dealer gets only one type of vaccine and difference in vaccine count of each dealer is minimum
// return the vaccine count of dealer with maximum vaccine count
int solve(vector<int> &arr,int n, int m)
{
    int res = INT_MAX;
    int j = 0;
    unordered_map<int,int> mp;
    for(int i=0;i<m;i++)
    {
        mp[arr[i]]++;
        while(mp.size() == n)
        {
            res = min(res,i-j+1);
            mp[arr[j]]--;
            if(mp[arr[j]] == 0)
            {
                mp.erase(arr[j]);
            }
            j++;
        }
    }
    return res;
}


int main(){
    int n = 5; //no of dealers
    int m = 2; //no of vaccines
    vector<int> arr = {7,4};
    cout<<solve(arr,n,m);
}