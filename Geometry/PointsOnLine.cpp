#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    /**
     * Maximum points on a line
     * @Algorithm:
     * 1. For each point, find the slope with all other points
     * 2. Store the slope in a map with count of points on that line
     * 3. Find the maximum count of points on a line 
     *        maxPoints = max(pointsWithSameSlope, verticalPoints)+1
     * 4. Repeat for all points
    */
    int maxPoints(vector<vector<int>> &points)
    {
        int n = points.size();
        if (n < 3)
            return n;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int same = 1; // for the point itself
            int vertical = 0; // for vertical lines
            unordered_map<double, int> m; //map for slope and count of points on that line
            for (int j = i + 1; j < n; j++)// for each point, find the slope with all other points
            {
                if (points[i][0] == points[j][0] && points[i][1] == points[j][1]) 
                    same++;
                else if (points[i][0] == points[j][0])
                    vertical++;
                else
                {
                    double slope = (double)(points[i][1] - points[j][1]) / (points[i][0] - points[j][0]);
                    m[slope]++;
                }
            }
            int maxPoints = 0;
            for (auto it : m)
                maxPoints = max(maxPoints, it.second);
            maxPoints = max(maxPoints, vertical);
            ans = max(ans, maxPoints + same);
        }
        return ans;
    }
};

