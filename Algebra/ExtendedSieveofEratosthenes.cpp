#include <bits/stdc++.h>
using namespace std;

void extendedSieve(vector<int> &prime, int n)
{
    bool visited[n + 1];

    for (int i = 0; i <= n; i++)
        visited[i] = true;

    for (int i = 2; i * i <= n; i++)
    {
        if (visited[i])
        {
            for (int j = i * i; j <= n; j += i)
                visited[j] = false;
        }
    }
    for (int i = 2; i <= n; i++)
        if (visited[i])
        {
            prime.push_back(i);
            cout << i << " ";
        }
}

int main()
{
    int n;
    n = 100;
    vector<int> prime;
    extendedSieve(prime, n);
    for (int i = 0; i < prime.size(); i++)
        cout << prime[i] << " ";
    return 0;
}