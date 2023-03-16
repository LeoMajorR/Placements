#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPossible(vector<int> &candies, int n, long long k, int mid)
    {
        long long candiesEaten = 0;
        for (int i = 0; i < n; i++)
        {
            candiesEaten += candies[i] / mid;
            if (candies[i] % mid != 0)
                candiesEaten++;
        }
        if (candiesEaten <= k)
            return true;
        return false;
    }

    int maximumCandies(vector<int> &candies, long long k)
    {
        int n = candies.size();
        sort(candies.begin(), candies.end());
        int low = 1, high = candies[n - 1];
        while (low <= high)
        {
            int mid = (low + high) >> 1;
            if (isPossible(candies, n, k, mid))
                high = mid - 1;
            else
                low = mid + 1;
        }
        return high;
    }
};

int main()
{
    Solution s;
    vector<int> candies = {5, 8, 6};
    long long k = 3;
    cout << s.maximumCandies(candies, k);
    return 0;
}
