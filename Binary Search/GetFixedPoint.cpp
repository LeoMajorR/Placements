#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getFixedPoint(vector<int> &arr, int low, int high)
    {
        if (low <= high)
        {
            int mid = (high + low) >> 1;
            if (arr[mid] == mid)
                return mid;
            else if (arr[mid] > mid)
                return getFixedPoint(arr, low, mid - 1);
            else
                return getFixedPoint(arr, mid + 1, high);
        }
        return -1;
    }
};

int main()
{
    Solution s;
    vector<int> arr = {-4, -2, 0, 1, 4, 6, 7};
    cout << s.getFixedPoint(arr, 0, arr.size() - 1);
    return 0;
}
