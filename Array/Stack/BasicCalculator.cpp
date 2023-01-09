#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    /**
     * s = "(1+(4+5+2)-3)+(6+8)"
     * output = 23
    */
    int calculate(string s)
    {
        int n = s.length();
        stack<int> st;
        int res = 0;
        int sign = 1;
        for(int i=0;i<n;i++)
        {
            if(s[i]>='0' && s[i]<='9') // if number
            {
                int num = 0;
                while(i<n && s[i]>='0' && s[i]<='9')
                {
                    num = num*10 + (s[i]-'0');
                    i++;
                }
                res += sign*num;
                i--;
            }
            // if sign
            else if(s[i]=='+')
                sign = 1;
            else if(s[i]=='-')
                sign = -1;
            // if bracket
            else if(s[i]=='(')
            {
                st.push(res);
                st.push(sign);
                res = 0;
                sign = 1;
            }
            else if(s[i]==')')
            {
                res = res*st.top();
                st.pop();
                res += st.top();
                st.pop();
            }
        }
        return res;
    }
};

int main()
{
    string s = "(1+(4+5+2)-3)+(6+8)";
    Solution obj;
    cout<<obj.calculate(s);
}

