#include <bits/stdc++.h>
using namespace std;

int minJumps(int arr[], int n)
{
    int i = 0, maxReachable = 0, jumps = 0, lastJumpedPos = 0;
    while (lastJumpedPos < n - 1)
    {
        maxReachable = max(maxReachable, i + arr[i]);
        if (i == lastJumpedPos)
        {
            jumps++;
            lastJumpedPos = maxReachable;
        }
        i++;
    }
    return jumps;
}