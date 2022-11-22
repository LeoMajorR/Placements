#include <bits/stdc++.h>
using namespace std;

int maxAggregateTempChange(vector<int> arr)
{
    int n = arr.size();
    vector<int> prefSUm, suffSum;
    prefSUm.push_back(arr[0]);
    suffSum.push_back(arr[n - 1]);
    for (int i = 1; i < n; i++)
    {
        prefSUm.push_back(prefSUm[i - 1] + arr[i]);
        suffSum.push_back(suffSum[i - 1] + arr[n - i - 1]);
    }
    int maxDiff = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        maxDiff = max({maxDiff, prefSUm[i], suffSum[n - i - 1]});
    }
    return maxDiff;
}

int main()
{
    vector<int> arr = {-1, 2, 3};
    vector<int> arr1 = {6, -2, 5};
    cout << maxAggregateTempChange(arr) << endl;
    cout << maxAggregateTempChange(arr1) << endl;
}