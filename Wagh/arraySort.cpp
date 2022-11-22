#include <bits/stdc++.h>
using namespace std;

int sort(vector<int> &arr)
{
    int n = arr.size();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int j = i;
        while (j < n && arr[j] != i + 1)
        {
            j++;
        }
        ans += j - i;
        while (j > i)
        {
            swap(arr[j], arr[j - 1]);
            j--;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr1 = {1, 3, 2};
    vector<int> arr2 = {5, 3, 2, 1, 4};
    cout << sort(arr1) << endl;
    cout << sort(arr2) << endl;
}