#include <bits/stdc++.h>
using namespace std;

int main()
{
    srand(time(0));
    int N = rand();
    // random no between 1 and log2(N))+1
    int k = rand() % (int)log2(N) + 1;

    cout << "N = " << N << endl;
    cout << "k = " << k << endl;

    cout << "Setting Kth Bit: " << (N | (1 << (k - 1))) << endl;
    cout << "Clearing Kth Bit: " << (N & ~(0 << (k - 1))) << endl;
    cout << "Toggling Kth Bit: " << (N ^ (1 << (k - 1))) << endl;
    return 0;
}