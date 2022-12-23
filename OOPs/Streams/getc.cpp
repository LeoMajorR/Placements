#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str = "Name";
    cout.width(10);
    // cout.fill('#');
    cout
        << str << endl;
    cout.precision(5);
    cout << 1.387563875 << endl;

    int n = -1653;
    std::cout.width(10);
    std::cout << std::internal << n << '\n';
    std::cout.width(10);
    std::cout << std::left << n << '\n';
    std::cout.width(10);
    std::cout << std::right << n << '\n';
}