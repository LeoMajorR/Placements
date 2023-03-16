#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPossible(vector<int> &piles, int n, int mid, int h)
    {
        double hours = 0;
        for (int i = 0; i < n; i++)
        {
            hours += piles[i] / mid;
            if (piles[i] % mid != 0)
                hours++;
        }
        if (hours <= h)
            return true;
        return false;
    }

    int minEatingSpeed(vector<int> &piles, int h)
    {
        int n = piles.size();
        sort(piles.begin(), piles.end());
        int low = 1, high = piles[n - 1];
        while (low <= high)
        {
            int mid = (low + high) >> 1;
            if (isPossible(piles, n, mid, h))
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};

int main()
{
    Solution s;
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;
    cout << s.minEatingSpeed(piles, h);
    return 0;
}
