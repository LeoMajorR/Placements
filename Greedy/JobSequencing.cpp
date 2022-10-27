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

// return the maximum profit and total jobs done
// (jobid, deadline, profit)
vector<int> jobScheduling(vector<vector<int>> &jobs)
{
    int n = jobs.size();
    sort(jobs.begin(), jobs.end(), [](vector<int> &a, vector<int> &b)
         { return a[2] > b[2]; });
    int maxDeadline = 0;
    for (int i = 0; i < n; i++)
    {
        maxDeadline = max(maxDeadline, jobs[i][1]);
    }
    vector<bool> slot(maxDeadline + 1, false);
    int profit = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = jobs[i][1]; j > 0; j--)
        {
            if (!slot[j])
            {
                slot[j] = true;
                profit += jobs[i][2];
                count++;
                break;
            }
        }
    }
    return {profit, count};
}

int main()
{
    vector<vector<int>> jobs = {{1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30}};
    vector<int> ans = jobScheduling(jobs);
    cout << ans;
    return 0;
}