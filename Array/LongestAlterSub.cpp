#include <bits/stdc++.h>
using namespace std;

int longAlterSubseq(int arr[], int n)
{
    int l[n][2];
    /**
     * l[i][0] : length of longest alter subsequence ending at i and last element is greater than previous element
     * l[i][1] : length of longest alter subsequence ending at i and last element is less than previous element
     * l[i][0] = max(l[i-1][0], l[i-1][1] + arr[i])
     * l[i][1] = max(l[i-1][1], l[i-1][0] - arr[i])
     */

    // initialize all values with 1

    int res = 1;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[i - 1])
            l[i][0] = max(l[i - 1][0] + 1, l[i - 1][1]);
        else
            l[i][1] = max(l[i - 1][1] + 1, l[i - 1][0]);
    }
    return res;
}

int main()
{
    int arr[] = {1, 17, 5, 10, 13, 15, 10, 5, 16, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << longAlterSubseq(arr, n) << endl;
    return 0;
}