#include <bits/stdc++.h>
using namespace std;

// n meeting in one room
int maxMeetings(vector<int> &startTime, vector<int> &endTime)
{
    int n = startTime.size();
    vector<pair<int, int>> meetings;
    for (int i = 0; i < n; i++)
    {
        meetings.push_back({endTime[i], startTime[i]});
    }
    sort(meetings.begin(), meetings.end());
    int count = 1;
    int end = meetings[0].first;
    for (int i = 1; i < n; i++)
    {
        if (meetings[i].second > end)
        {
            count++;
            end = meetings[i].first;
        }
    }
    return count;
}

int main()
{
    vector<int> startTime = {1, 3, 0, 5, 8, 5};
    vector<int> endTime = {2, 4, 6, 7, 9, 9};
    cout << maxMeetings(startTime, endTime) << endl;
    return 0;
}