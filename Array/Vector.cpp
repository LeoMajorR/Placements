#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {1,2,4,5};
    auto it =  lower_bound(arr.begin(), arr.end(), 3);
    cout << *it << endl;
}