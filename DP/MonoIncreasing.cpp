#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    /**
     * @Algorithm
     * 1. Find the first 1 and last 0
     * 2. Count the number of 0s and 1s between first 1 and last 0
     * 3. Return the minimum of the two counts
     * 
    */
    int minFlipsMonoIncreasing(string s)
    {
        int counterOne=0, counterFlip=0; // counterOne is the number of 1s, counterFlip is the number of flips
        for(auto ch:s)
        {
            if(ch=='1')
            {
                counterOne++;
            }
            else
            {
                counterFlip++;
            }
            counterFlip=min(counterOne, counterFlip);
        }
        return counterFlip;
    }
};

int main()
{
    Solution s;
    string str1 ="010110";
    string str2 = "00011000";
    string str3="10011111110010111011";
    cout<<s.minFlipsMonoIncreasing(str1)<<endl;
    cout<<s.minFlipsMonoIncreasing(str2)<<endl;
    cout<<s.minFlipsMonoIncreasing(str3)<<endl;
    return 0; 
}