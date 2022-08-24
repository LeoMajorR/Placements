#include <bits/stdc++.h>
using namespace std;

int lenOfLongSubarr(int A[], int N, int K)
{
    // Complete the function
    map<int, int> mp;
    mp[0] = -1;
    int sum = 0, ans = 0;
    for (int i = 0; i < N; i++)
    {
        sum += A[i];
        if (mp.find(sum - K) != mp.end())    // if sum - K is present in map
            ans = max(ans, i - mp[sum - K]); // update ans with max length of subarray
        if (mp.find(sum) == mp.end())        // if sum is not present in map
            mp[sum] = i;                     // insert sum and its index in map
    }
    // display the map
    for (auto it : mp)
        cout << it.first << " " << it.second << endl;
    return ans;
}

int main()
{
    int K = 15;
    int A[] = {10, 5, 2, 7, 1, 9};
    int N = sizeof(A) / sizeof(A[0]);
    cout << lenOfLongSubarr(A, N, K);
    return 0;
}