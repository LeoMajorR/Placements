#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a = 3, b = 4;
    function <int(int, int)> sum = [&] (int a, int b) -> int {
        return a + b;
    };
    cout << sum(a, b) << endl;

    // max of two numbers
    function <int(int, int)> max = [&] (int a, int b) -> int {
        return a > b ? a : b;
    };

    // 
    return 0;
}