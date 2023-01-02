#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    vector<int> closestPrimes(int left, int right)
    {
        vector<int> ans(2, -1);
        if(left==right) return ans;
        vector<bool> number(right-left, true);
        if(left==1) number[0] = false;
        for(int i = 2; i*i <= right; i++) {
            for(int j = max(2, (left+i-1)/i)*i; j <= right; j += i) {
                number[j-left] = false;
            }
        }
        //primes with smallest gap
        int minGap = right-left-1;
        for(int i = left; i < right; i++) {
            if(number[i-left]) {
                for(int j = i+1; j <= right; j++) {
                    if(number[j-left]) {
                        if(j-i < minGap) {
                            minGap = j-i;
                            ans[0] = i;
                            ans[1] = j;
                        }
                        break;
                    }
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> ans = s.closestPrimes(10, 19);
    cout<<ans[0]<<" "<<ans[1]<<endl;
    vector<int> ans1 = s.closestPrimes(4, 6);
    cout<<ans1[0]<<" "<<ans1[1]<<endl;
    return 0;
}

