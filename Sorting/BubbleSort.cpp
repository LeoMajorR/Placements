#include <bits/stdc++.h>
using namespace std;

/**
 *  Bubble Sort
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
void bubbleSort(vector<int> &arr, bool printIterations = false)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
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
    bubbleSort(arr, true);
    cout << "Sorted Array: ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}