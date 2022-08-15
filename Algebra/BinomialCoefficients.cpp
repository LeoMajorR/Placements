#include <bits/stdc++.h>
using namespace std;

// using Pascal's Triangle
int binomialCoefficient(int n, int k)
{
    int C[n + 1][k + 1];
    C[0][0] = 1; // base case
    // value of binomial coefficient in bottom up manner
    for (int i = 1; i <= n; i++)
    {
        C[i][0] = C[i][i] = 1; // base case
        for (int j = 1; j < i; j++)
        {
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
    return C[n][k];
}

int main()
{
    int n, k;
    n = 5, k = 2;
    cout << binomialCoefficient(n, k) << endl;
    return 0;
}