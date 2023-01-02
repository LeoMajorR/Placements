#include <bits/stdc++.h>
using namespace std;

template <typename T>
std::ostream & operator << (std::ostream & os, const std::vector<T> & vec)
{
    for(auto elem : vec)
    {
        os<<elem<< " ";
    }
    return os;
}

class Solution {
    public:
    bool isPrime(int n)
    {
        if (n <= 1) {
            return false;
        }
        for (int i = 2; i*i <= n; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
    int primeFactorise(int n)
    {
        int factorsSum=0;
        for (int i = 2; i <= n; i++) {
            while (n % i == 0) {
                factorsSum+=i;
                n /= i;
            }
        }
        return factorsSum;
    }

    // continuously replace n with the sum of its prime factors
    int smallestValue(int n)
    {
        if(n==1 || n==4) return n;
        while(!isPrime(n))
        {
            int sum=0;
            for(int i=2;i<=n;i++)
            {
                while(n%i==0)
                {
                    sum+=i;
                    n/=i;
                }
            }
            n = sum;
        }
        return n;
    }
};

int main()
{
    Solution sol;
    int n = 12;
    cout << sol.smallestValue(15) << endl;
    cout<<sol.smallestValue(3)<<endl;
    cout<<sol.smallestValue(9)<<endl;
    cout<<sol.smallestValue(4)<<endl;
    return 0;
}