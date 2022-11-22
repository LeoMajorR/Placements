#include <bits/stdc++.h>
using namespace std;

int smallestSubstring(string s)
{
    unordered_set<char> st;

    for(int i=0;i<s.length();i++)
    {
        st.insert(s[i]);
    }

    int unique = st.size();

    unordered_map<char,int> mp;
    int res = INT_MAX;
    int j = 0;

    for(int i=0;i<s.length();i++)
    {
        mp[s[i]]++;

        while(mp.size() == unique)
        {
            res = min(res,i-j+1);
            mp[s[j]]--;
            if(mp[s[j]] == 0)
            {
                mp.erase(s[j]);
            }
            j++;
        }
    }

    return res;

}

int main()
{
    string s = "abcda";
    cout << smallestSubstring(s);
}