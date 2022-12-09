#include <bits/stdc++.h>
using namespace std;

bool isBadVersion(int version)
{
    return true;
}

int firstBadVersion(int n)
{
    int low = 0, high = n;
    while(low<high)
    {
        int mid = low + (high-low)/2;
        if(isBadVersion(mid))
            high = mid;
        else
            low = mid+1;
    }
    return low;
}