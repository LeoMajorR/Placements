#include <bits/stdc++.h>
using namespace std;

string reverseVowels(string s)
{
    int n = s.size();
    int i = 0, j = n - 1;
    while (i < j)
    {
        while (i < j && !strchr("aeiouAEIOU", s[i]))
            i++;
        while (i < j && !strchr("aeiouAEIOU", s[j]))
            j--;
        swap(s[i++], s[j--]);
    }
    return s;
}