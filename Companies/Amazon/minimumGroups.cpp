#include <bits/stdc++.h>
using namespace std;

// minimum number of groups such that difference b/w numbers in a group must not exceed k
int minimumGroups(vector<int> awards, int k)
{
    int n = awards.size();
    sort(awards.begin(), awards.end());
    int count = 1;
    int i = 0;
    int j = 1;
    while (j < n)
    {
        if (awards[j] - awards[i] > k)
        {
            count++;
            i = j;
        }
        j++;
    }
    return count;
}

int main()
{
    vector<int> awards = {1, 13,6,8,9,3,5};
    int k = 4;
    cout << minimumGroups(awards, k);
    return 0;
}