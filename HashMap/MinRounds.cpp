#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int minimumRounds(vector<int> &tasks)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < tasks.size(); i++) {
            mp[tasks[i]]++;
        }
        int count=0;
        for(auto it = mp.begin();it!=mp.end();it++){
            if(it->second==1) return -1;
            count+=static_cast<int>(ceil(it->second/3.0));  
        }
        return count;
    }
};


int main()
{
    Solution s;
    vector<int> tasks = { 2,2,3,3,2,4,4,4,4,4};
    cout << s.minimumRounds(tasks)<<endl;
    vector<int> tasks1 = {2,3,3};
    cout << s.minimumRounds(tasks1)<<endl;
    vector<int> tasks2={5,5,5,5};
    cout << s.minimumRounds(tasks2)<<endl;
    return 0;
}
