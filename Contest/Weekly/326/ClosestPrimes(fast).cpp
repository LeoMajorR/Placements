#include <bits/stdc++.h>
using namespace std;

int N = 1e6;

vector<bool> isPrime(N + 1, true);
vector<int> primes;

void init() {
    if (!isPrime[0]) {
        return;
    }
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i < N; ++i) {
        if (!isPrime[i]) {
            continue;
        }
        primes.push_back(i);
        for (int j = i + i; j <= N; j += i) {
            isPrime[j] = false;
        }
    }
}

class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        init();
        int minD = N;
        int num1 = -1;
        int num2 = -1;
        
        int n = primes.size();
        for (int i = 0; i < n - 1; ++i) {
            int d = primes[i+1] - primes[i];
            if (d < minD && primes[i] >= left && primes[i + 1] <= right) {
                minD = d;
                num1 = primes[i];
                num2 = primes[i+1];
            }
        }
        
        return vector<int>{num1, num2};
    }
};