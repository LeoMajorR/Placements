#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPossible(vector<int> &stalls, int n, int k, int mid)
    {
        int cows = 1, last = stalls[0];
        for (int i = 1; i < n; i++)
        {
            if (stalls[i] - last >= mid)
            {
                cows++;
                last = stalls[i];
            }
            if (cows == k)
                return true;
        }
        return false;
    }

    int aggressiveCows(vector<int> &stalls, int k)
    {
        int n = stalls.size();
        sort(stalls.begin(), stalls.end());
        int low = 0, high = stalls[n - 1] - stalls[0];
        while (low <= high)
        {
            int mid = (low + high) >> 1;
            if (isPossible(stalls, n, k, mid))
                low = mid + 1;
            else
                high = mid - 1;
        }
        return high;
    }
};

int main()
{
    Solution s;
    vector<int> stalls = {1, 2, 4, 8, 9};
    int k = 3;
    cout << s.aggressiveCows(stalls, k);
    return 0;
}
