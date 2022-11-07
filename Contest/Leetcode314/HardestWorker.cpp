#include <bits/stdc++.h>
using namespace std;

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &vec)
{
    for (auto elem : vec)
    {
        os << elem << " ";
    }
    return os;
}

// log : {{id, leaveTime}, {id, leaveTime}, ...}
// ith task time = leaveTime[i] - leaveTime[i-1]
// return the id of the hardest worker
int hardestWorker(int n, vector<vector<int>> &logs)
{
    vector<int> time(n, 0);
    time[logs[0][0]] = logs[0][1];
    for (int i = 1; i < logs.size(); i++)
    {
        time[logs[i][0]] = max(time[logs[i][0]], logs[i][1] - logs[i - 1][1]);
    }
    int maxTime = *max_element(time.begin(), time.end());
    // index of maxTime
    int index = find(time.begin(), time.end(), maxTime) - time.begin();
    return index;
}

int main()
{
    vector<vector<int>> logs = {{0, 3}, {2, 5}, {0, 9}, {1, 15}};
    cout << hardestWorker(10, logs) << endl;
    return 0;
}