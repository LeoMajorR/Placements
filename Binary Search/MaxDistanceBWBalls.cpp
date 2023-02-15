#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canPlace(vector<int> &position, int m, int mid)
    {
        int n = position.size();
        int count = 1;
        int last = position[0];
        for (int i = 1; i < n; i++)
        {
            if (position[i] - last >= mid)
            {
                count++;
                last = position[i];
            }
        }
        return count >= m;
    }

    int maxDistance(vector<int> &position, int m)
    {
        sort(position.begin(), position.end());
        int n = position.size();
        int low = 0, high = position[n - 1] - position[0];
        while (low < high)
        {
            int mid = low + (high - low + 1) / 2;
            if (canPlace(position, m, mid))
                low = mid;
            else
                high = mid - 1;
        }
        return low;
    }
};

int main()
{
    vector<int> positions = {1, 2, 3, 4, 7};
    cout << Solution().maxDistance(positions, 3);
}