#include <bits/stdc++.h>
using namespace std;

//
int eraseOverlapIntervals(vector<vector<int>> &intervals)
{
    if (intervals.size() == 0)
        return 0;
    sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b) {
        return a[1] < b[1];
    });
    int count = 1; //to keep count of non-overlapping intervals
    int end = intervals[0][1];
    for (int i = 1; i < intervals.size(); i++)
    {
        if (intervals[i][0] >= end)
        {
            count++;
            end = intervals[i][1];
        }
    }
    return intervals.size() - count; // total intervals - non-overlapping intervals
}

int main()
{
    vector<vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    cout << eraseOverlapIntervals(intervals);
    return 0;
}