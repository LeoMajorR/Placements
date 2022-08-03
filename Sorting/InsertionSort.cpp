#include <bits/stdc++.h>
using namespace std;

/**
 *  Insertion Sort
 *  Time Complexity: O(n^2)
 *
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

void insertionSort(vector<int> &arr, bool printIterations = false)
{
    int n = arr.size();
    for (int i = 1; i < n; i++) // Start from 1 as arr[0] is already sorted
    {
        int key = arr[i];
        int j = i - 1;
        // Move elements of arr[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        // place current element at the correct position
        arr[j + 1] = key;
        if (printIterations)
        {
            cout << "Iteration " << i << ": " << arr << endl;
        }
    }
}

int main()
{
    // vector of 50 elements
    vector<int> arr = {2, 34, 6, 46, 4755, 3, 63, 0, 58, 8, 8, 63, 5, 36, 47, 585, 8, 58, 686, 1, 636, 36, 82};
    insertionSort(arr, true);
    cout << "Sorted Array: ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}