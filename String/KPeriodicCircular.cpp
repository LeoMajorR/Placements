#include <bits/stdc++.h>
using namespace std;

/*
 * Input : s="abba" k=2
 * Output: abab
 *
 * Input : s="abbba" k=2
 * Output: -1
 *
 * Input : s="geeksgeeks" k=5
 * Output: eegkseegks
 *
 * Input : s="aa" k=7
 * Output: aa
 * Explanation: The string is already periodic.
 *
 * Lexicographically smallest permutation of string s is kth periodic
 */

string lexoString(map<int, int> &m, int k, int p)
{
    string ans = "";
    string final = "";
    for (auto it = m.begin(); it != m.end(); it++)
    {
        int cnt = it->second;
        int repeat = cnt / p;
        while (repeat--)
            ans += it->first + 'a';
    }
    // repeat ans k times
    for (int i = 0; i < p; i++)
        final += ans;
    return final;
}

string kPeriodicCircular(string s, int k)
{
    map<int, int> m;
    for (int i = 0; i < s.length(); i++)
    {
        m[s[i] - 'a']++;
    }
    int n = s.length();
    int period = n / k;
    if (m.size() == 1)
        return s;
    if (n < k)
    {
        // return lexicographically smallest permutation of string s
        return lexoString(m, 1, period);
    }
    for (auto it = m.begin(); it != m.end(); it++)
    {
        if (it->second % period != 0)
            return "-1";
    }
    if (n % k == 0)
    {
        // return lexicographically smallest permutation of string s
        return lexoString(m, k, period);
    }
    else
        return "-1";
}

int main()
{
    string s = "abba";
    int k = 2;
    cout << kPeriodicCircular(s, k) << endl;
    s = "geeksgeeks";
    k = 5;
    cout << kPeriodicCircular(s, k) << endl;
    s = "aa";
    k = 7;
    cout << kPeriodicCircular(s, k) << endl;
    s = "bbbbabba";
    k = 2;
    cout << kPeriodicCircular(s, k) << endl;
    return 0;
}

/**
 * Another Iteration
 * string kPeriodic(string s, int k){
        // code here
    map<int, int> m;
    for (int i = 0; i < s.length(); i++)
    {
        m[s[i] - 'a']++;
    }
    if (m.size() == 1)
    {
        return s;
    }
    int period = s.size() / k;
    if (s.size() % k != 0)
        return "-1";
    // check if counts are even
    bool flag = true;
    for (auto it = m.begin(); it != m.end(); it++)
    {
        if (it->second % period != 0)
        {
            flag = false;
            break;
        }
    }
    if (!flag)
    {
        return "-1";
    }
    // create substring of length k
    string ans = "";
    for (auto it = m.begin(); it != m.end(); it++)
    {
        int tempCount = it->second;
        int repeat = tempCount / period;
        while (repeat > 0)
        {
            ans += it->first + 'a';
            repeat--;
        }
    }
    for (int i = 0; i < period - 1; i++)
    {
        ans += ans;
    }
    return ans;
    }
 */