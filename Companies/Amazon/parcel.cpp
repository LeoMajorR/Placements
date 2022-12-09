#include <bits/stdc++.h>
using namespace std;

// truck caries k parcels
// parcels[] : no of parcels already in the truck
//
long getMinimumCost(vector<int> parcels, int k)
{
    int n = parcels.size();
    if (n == 0)
        return 0;

    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        m[parcels[i]] = 1;
    }

    int i = 1;
    int cost = 0;

    while (i <= k && n != k)
    {
        if (m.find(i) == m.end())
        {
            m[i] = 1;
            cost = cost + i;
            n = n + 1;
        }
        i++;
    }
    return cost;
}

int main()
{
    vector<int> parcels = {2, 3, 6, 10, 11};
    int k = 9;
    cout << getMinimumCost(parcels, k) << endl;
    return 0;
}