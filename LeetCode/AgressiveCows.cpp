#include <bits/stdc++.h>
using namespace std;

bool isPossible(int arr[], int n, int c, int mid)
{
    int cowsCount = 0;
    int lastPlacdCow = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] - lastPlacdCow >= mid)
        {
            cowsCount++;
            lastPlacdCow = arr[i];
        }
    }
    if (cowsCount >= c)
        return true;
    return false;
}

int main()
{
    int t, n, c;
    cin >> t;
    cin >> n >> c;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    int low = 1, high = a[n - 1] - a[0];
    while (low <= high)
    {
        int mid = (low + high) >> 1;
        if (isPossible(a, n, c, mid))
            low = mid + 1;
        else
            high = mid - 1;
    }
    cout << high << endl;

    return 0;
}