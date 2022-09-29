#include <bits/stdc++.h>
using namespace std;

// consider only subset of m rows to increase net vulnerability.
// find max possible value of net vulnerability for given m -1 rows from grid
int gettMaxVulnerability(int n, int m, vector<vector<int>> nat)
{
    // algorithm
    // choose n-1 rows
    // find max value for each column
    // lowest value of max value of each column is the answer
}

int main()
{
    int n = 4, m = 3;
    vector<vector<int>> vulnerability = {{1, 3, 1}, {3, 1, 1}, {1, 2, 2}, {1, 1, 3}};
    int ans = gettMaxVulnerability(n, m, vulnerability);
    cout << ans << endl;
}