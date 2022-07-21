#include <bits/stdc++.h>
using namespace std;

/**
 * @brief NativeSearch::Native String Search Algorithm
 *
 */

int nativeSearch(string s, string t)
{
    int m = s.size();
    int n = t.size();

    for (int i = 0; i <= m - n; i++)
    {
        int j = 0;
        while (j < n && s[i + j] == t[j])
            j++;
        if (j == n)
            return i;
    }
    return -1;
}

int main()
{
    // s => string
    // t => pattern
    string s = "This is test string";
    string t = "test";
    if (nativeSearch(s, t) != -1)
        cout << "String " << t << " is present at index " << nativeSearch(s, t) << endl;
    else
        cout << "String " << t << " is not present in " << s << endl;

    s = "One of the fastest programming language is C++";
    t = "C++";
    if (nativeSearch(s, t) != -1)
        cout << "String " << t << " is present at index " << nativeSearch(s, t) << endl;
    else
        cout << "String " << t << " is not present in " << s << endl;
    return 0;
}