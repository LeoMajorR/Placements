#include <bits/stdc++.h>
using namespace std;

// for sorted array
vector<int> twoSum(vector<int> &arr, int target)
{
    int n = arr.size();
    int i = 0, j = n - 1;
    vector<int> ans;
    while (i < j)
    {
        if (arr[i] + arr[j] == target)
        {
            ans.push_back(i);
            ans.push_back(j);
            return ans;
        }
        else if (arr[i] + arr[j] < target)
            i++;
        else
            j--;
    }
    return ans;
}

int twoSum(vector<int> arr, int x)
{
    int n = arr.size();
    int i = 0, j = n - 1;
    while (i < j)
    {
        if (arr[i] + arr[j] == x)
            return 1;
        else if (arr[i] + arr[j] < x)
            i++;
        else
            j--;
    }
    return 0;
}