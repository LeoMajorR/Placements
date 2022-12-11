#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s)
{
    string ans="";
    for(int i=0;i<s.size();i++)
    {
        if(s[i]==' ')
        {
            ans+=' ';
            continue;
        }
        int j=i;
        while(j<s.size() && s[j]!=' ')
            j++;
        for(int k=j-1;k>=i;k--)
            ans+=s[k];
        i=j-1;
    }
    return ans;
}