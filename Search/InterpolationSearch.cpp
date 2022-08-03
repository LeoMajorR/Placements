#include <bits/stdc++.h>
using namespace std;

/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * @input B : Integer
 *
 *
 * interpolation search formula is : index = lower + (B - A[lower]) * (upper - lower) / (A[upper] - A[lower])
 * @Output Integer
 */

int interpolationSearch(vector<int> &arr, int n, int x)
{
    int low = 0, high = n - 1;
    while (low <= high && x >= arr[low] && x <= arr[high])
    {
        int pos = low + (((double)(high - low) / (arr[high] - arr[low])) * (x - arr[low])); // formula for interpolation search
        if (arr[pos] == x)
            return pos;
        if (arr[pos] < x)
            low = pos + 1;
        else
            high = pos - 1;
    }
    return -1;
}

int main()
{
    vector<int> arr1 = {1, 3, 15, 18, 90, 1500, 2000, 50000};
    vector<int> arr2 = {2, 3, 6, 8, 10, 13, 16, 18};
    int ind1 = interpolationSearch(arr1, arr1.size(), 50000);
    int ind2 = interpolationSearch(arr2, arr2.size(), 10);
    cout << ind1 << " " << ind2;
    return 0;
}