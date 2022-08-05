#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int l, int r)
{
    int piv = arr[r];
    int i = l;
    for (int j = l; j < r; j++)
    {
        if (arr[j] <= piv)
        {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[r]);
    return i;
}

int kthSmallestUtil(vector<int> &arr, int l, int r, int k)
{
    if (k > 0 && k <= r - l + 1)
    {
        int index = partition(arr, l, r);
        if (index - l == k - 1)
            return arr[index];
        else if (index - l > k - 1)
            return kthSmallestUtil(arr, l, index - 1, k);
        else
            return kthSmallestUtil(arr, index + 1, r, k - index + l - 1);
    }
    return -1;
}

int kthSmallest(vector<int> &arr, int k)
{
    int l = 0, r = arr.size() - 1;
    int ans = kthSmallestUtil(arr, l, r, k);
    return ans;
}

int main()
{
    vector<int> arr = {3, 2, 1, 5, 6, 4};
    vector<int> arr1 = {1, 3, 36, 2, 42, 64, 75, 47635, 25, 475, 768};
    vector<int> arr2 = {3, 2, 3, 1, 2, 4, 5, 5, 6};

    cout << kthSmallest(arr, 3) << endl;
    cout << kthSmallest(arr1, 3) << endl;
    cout << kthSmallest(arr2, 1) << endl;
    return 0;
}