#include <bits/stdc++.h>
using namespace std;


//return longest palindrome that can be built with the letters in s
int longestPalindrome(string s)
{
    int count[256] = {0};
    for(int i=0;i<s.length();i++)
    {
        count[s[i]]++;
    }
    int ans = 0;
    for(int i=0;i<256;i++)
    {
        ans += count[i]/2*2; //if count is even then add it to ans
    }
    if(ans<s.length()) //if ans is less than s.length() then we can add 1 to it
        ans++;
    return ans;
}

int main()
{
    string s = "abccccdd";
    cout<<longestPalindrome(s);
}