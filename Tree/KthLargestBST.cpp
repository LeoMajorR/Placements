#include <bits/stdc++.h>
using namespace std;

int findZeroes(int arr[], int n, int m)
{
    // code here
    int l = 0, r = 0;
    int ans = 0, curr = 0, zeros = 0;
    while (r < n)
    {
        // If current element is 0, increment count of zeros
        if (!arr[r])
        {
            // if count is less then m then increase windows size towards right
            if (zeros < m)
                zeros++, curr++;
            // if count is equal to m then increase left side of window
            else
                // if left side is zero then decrease count of zero
                while (arr[l++])
                    curr--;
        }
        // if not zero then increase window size towards right
        else
            curr++;
        ans = max(ans, curr);
        r++;
    }
    return ans;
}

int main()
{
    int arr[] = {1, 0, 0, 1, 1, 0, 1, 0, 1, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int m = 2;
    cout << findZeroes(arr, n, m);
    return 0;
}