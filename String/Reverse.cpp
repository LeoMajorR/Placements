#include <bits/stdc++.h>
using namespace std;

string reverse(string s)
{
    int i = 0, j = s.length() - 1;
    while (i < j)
    {
        if (s[i] == '|' || s[i] == '$')
            i++;
        else if (s[j] == '|' || s[j] == '$')
            j--;
        else
        {
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }
    return s;
}

int main()
{
    string a = "ab|cdef$hig";
    cout << reverse(a);
}