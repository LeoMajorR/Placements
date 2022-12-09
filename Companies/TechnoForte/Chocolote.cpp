#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        unordered_map<string, int> mp;
        while (n--)
        {
            int p;
            cin >> p;
            for (int i = 0; i < p; i++)
            {
                string str;
                cin >> str;
                mp[str]++;
            }
        }
        if (mp.size() == k)
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
    }
    return 0;
}