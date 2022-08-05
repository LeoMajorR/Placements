#include <bits/stdc++.h>
using namespace std;

/**
 *  Kth largest in unsorted array
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &vec)
{
    for (auto elem : vec)
    {
        os << elem << " ";
    }
    return os;
}

int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[low];
    int h = high;
    int l = low + 1;
    while (l <= h)
    {
        // if pivot is greater than current element, move pivot to right
        if (arr[l] < pivot && arr[h] > pivot)
        {
            swap(arr[l], arr[h]);
            l++;
            h--;
        }

        // if pivot is less than current element, move current index to right
        else if (arr[l] >= pivot)
            l++;

        // if pivot is greater than current element, move current index to left
        else
            h--;
    }
    swap(arr[low], arr[h]);
    return h;
}

int kthLargest(vector<int> &arr, int k)
{
    int r = arr.size() - 1;
    int l = 0;
    int kth;
    while (true)
    {
        int ind = partition(arr, l, r); // Arranging elements in descending order and returning the index of the kth largest element
        if (ind == k - 1)
        {
            kth = arr[ind];
            break;
        }
        else if (ind > k - 1)
        {
            r = ind - 1;
        }
        else
        {
            l = ind + 1;
        }
    }
    return kth;
}

int main()
{
    vector<int> arr = {3, 2, 1, 5, 6, 4};
    vector<int> arr1 = {1, 3, 36, 2, 42, 64, 75, 47635, 25, 475, 768};
    vector<int> arr2 = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    cout << kthLargest(arr, 2) << endl;
    cout << kthLargest(arr1, 1) << endl;
    cout << kthLargest(arr2, 4) << endl;
    return 0;
}