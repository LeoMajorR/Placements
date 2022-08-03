#include <bits/stdc++.h>
using namespace std;

/**
 *  Selection Sort
 *  Time Complexity: O(n^2)
 *
 */

void selectionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        swap(arr[i], arr[min]);
    }
}

int main()
{
    // vector of 50 elements
    vector<int> arr = {2, 34, 6, 46, 4755, 3, 63, 0, 58, 8, 8, 63, 5, 36, 47, 585, 8, 58, 686, 1, 636, 36, 82};
    selectionSort(arr);
    cout << "Sorted Array: ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}