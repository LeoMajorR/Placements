#include <bits/stdc++.h>
using namespace std;

vector<int> sieve(int n)
{
    vector<int> primes;
    bool isPrime[n + 1];
    memset(isPrime, true, sizeof(isPrime));
    for (int p = 2; p * p <= n; p++)
    {
        if (isPrime[p] == true)
        {
            for (int i = p * 2; i <= n; i += p)
                isPrime[i] = false;
        }
    }
    for (int p = 2; p <= n; p++)
        if (isPrime[p])
            primes.push_back(p);
    return primes;
}

int main()
{
    int n;
    n = 100;
    vector<int> primes = sieve(n);
    for (int i = 0; i < primes.size(); i++)
        cout << primes[i] << " ";
    return 0;
}