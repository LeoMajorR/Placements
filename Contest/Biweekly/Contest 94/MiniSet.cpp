#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    // return maximum of both arrays
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2)
    {
         int l = 1, r = INT_MAX, g = lcm(divisor1, divisor2);

        while(l<r){
            int m = l+ (r-l)/2;

            bool x = m - m/divisor1>=uniqueCnt1;
            bool y = m - m/divisor2>=uniqueCnt2;
            bool z = m - m/g>=uniqueCnt1+uniqueCnt2;

            if(x and y and z)
                r = m;
            else
                l = m+1;
        }
        return l;
    }
};

int main()
{
    Solution s;
    cout << s.minimizeSet(2, 7, 1, 3) << endl;
    cout<<s.minimizeSet(78789, 42659, 58291, 182389) << endl;

}