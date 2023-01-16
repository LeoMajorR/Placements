#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    string categorizeBox(int length, int width, int height, int mass)
    {
        bool bulky = ((length>=10e4 || width>=10e4 || height>=10e4)||(long long)length*width*height>=10e9)?true:false;
        
        bool heavy = mass>100;

        if(bulky && heavy)
            return "Both";
        else if(!bulky && !heavy)
            return "Neither";
        else if(bulky && !heavy)
            return "Bulky";
        else
            return "Heavy";
    }
};

int main()
{
    Solution s;
    int length = 3223, width=1271, height=2418, mass = 749;
    cout << s.categorizeBox(length, width, height, mass) << endl;
    return 0;
}
