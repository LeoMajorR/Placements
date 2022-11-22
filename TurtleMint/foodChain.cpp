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

// find point which is at min distance from all the points in given range
long long calculate(vector<long long> A, int start, int end)
{
    // initialise middle element as pivot

    long long res = A[(start + end) / 2];

    // minimise the distance of pivot from all the elements in given range
    for (int i = start; i <= end; i++)
    {
        if (abs(A[i] - res) < abs(A[(start + end) / 2] - res))
        {
            res = A[i];
        }
    }
    return res;
}

int solve(vector<long long> &A, int N, int K)
{
    sort(A.begin(), A.end());

    long long res = INT_MIN;

    vector<long long> medians;

    for (int i = 0; i < N; i += N / K)
    {
        medians.push_back(calculate(A, i, i + N / K));
    }
    // cout << medians << endl;

    for (int i = 0; i < N; i++)
    {
        long long minDist = INT_MAX;
        for (int j = 0; j < medians.size(); j++)
        {
            minDist = min(minDist, abs(A[i] - medians[j]));
        }
        res = max(res, minDist);
    }

    return res;
}

int main()
{
    int N = 3;
    int K = 1;
    vector<int> A = {1, 7, 12};
    vector<int> arr1 = {9, 63, 22, 2, 15, 58};
    // cout << solve(A, 6, 3);
    cout << solve(arr1, 6, 3);
}