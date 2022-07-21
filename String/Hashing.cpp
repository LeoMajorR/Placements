#include <bits/stdc++.h>
using namespace std;

/**
 * @brief The Hash Function
 * hash(s) = sum of (s[i] * (31^i)) % m
 *
 */

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &vec)
{
    for (auto elem : vec)
    {
        os << elem << " ";
    }
    return os;
}

long long int computeHash(string s)
{
    const int p = 31;
    const int m = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;
    for (int i = 0; i < s.size(); i++)
    {
        hash_value = (hash_value + (s[i] - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}

vector<vector<int>> groupIdenticalStrings(vector<string> const &str)
{
    int n = str.size();
    cout << "called" << endl;
    vector<pair<long long int, int>> hashes;

    for (int i = 0; i < n; i++)
    {
        hashes[i] = {computeHash(str[i]), i};
        cout << hashes[i].first << " " << hashes[i].second << endl;
    }
    sort(hashes.begin(), hashes.end());

    cout << "called" << endl;

    vector<vector<int>> groups;
    for (int i = 0; i < n; i++)
    {
        if (i == 0 || hashes[i].first != hashes[i - 1].first)
            groups.emplace_back();
        groups.back().push_back(hashes[i].second);
    }
    // display groups
    cout << groups.size() << endl;
    return groups;
}

int main()
{
    string s;
    // input string
    // cin >> s;
    s = "abcdakbfakjf";
    // hash function
    // long long int hash_value = computeHash(s);
    // output hash value
    // cout << "Hash Value of String " << s << " is :" << hash_value << endl;

    // Group identical strings
    vector<string> str_lst = {"abcd", "akbf", "akjf", "abcd", "akbf", "akjf"};
    vector<vector<int>> group_lst = groupIdenticalStrings(str_lst);

    // output group list
    cout << "Group List :" << endl;
    for (auto group : group_lst)
    {
        cout << group << endl;
    }
    return 0;
}