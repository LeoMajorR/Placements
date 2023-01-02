#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int distinctPrimeFactors(vector<int> &nums)
    {
        unordered_set<int> primeFactors;
        for(auto &x:nums)
        {
            for(int i=2;i*i<=x;i++)
            {
                for(;x%i==0;x/=i)
                {
                    primeFactors.insert(i);
                }
            }
            if(x>1)
            {
                primeFactors.insert(x);
            }
        }
        return primeFactors.size();
    }
};


int main()
{
    vector<int> num = {2,4,3,7,19,6};
    Solution ob;
    cout << ob.distinctPrimeFactors(num) << endl;
    return 0;
}
