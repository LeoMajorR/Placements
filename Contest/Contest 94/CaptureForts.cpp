#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    /**
     * @param forts: the position of forts
     * -1 : no fort at position i
     * 0 : enemy at position i
     * 1 : your fort at position i
     * return maximun number of forts you can capture in one move from ith fort to empty fort jth
    */
    int captureForts(vector<int> &forts)
    {
        int n= forts.size();

        int ans = 0;
        
        int count=0;
        bool flag=false;
        for(int i=0;i<n;i++)
        {
            if(forts[i]==1)
            {
                count=0;
                flag=true;
            }
            else if(forts[i]==0)
            {
                if(flag)
                    count++;
            }
            else
            {
                if(flag)
                {
                    ans=max(ans,count);
                    flag=false;
                }
            }
        }

        count=0;
        flag=false;
        for(int i=n-1;i>=0;i--)
        {
            if(forts[i]==1)
            {
                count=0;
                flag=true;
            }
            else if(forts[i]==0)
            {
                if(flag)
                    count++;
            }
            else
            {
                if(flag)
                {
                    ans=max(ans,count);
                    flag=false;
                }
            }
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> forts = {1,0,0,-1,0,0,0,0,1};
    vector<int> forts2 = {0,0,1,-1};
    vector<int> forts3 = {1,-1,-1,1,1};
    vector<int> forts4={1,-1,1,0,-1,-1,-1,-1,-1,-1,1};
    cout << sol.captureForts(forts) << endl;
    cout << sol.captureForts(forts2) << endl;
    cout << sol.captureForts(forts3) << endl;
    cout << sol.captureForts(forts4) << endl;
    return 0;
}

