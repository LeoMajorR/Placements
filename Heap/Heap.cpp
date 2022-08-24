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

// heapify
void heapify(vector<int> &arr, int i)
{
    int size = arr.size();
    int largest = i;

    // left and right child
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    // setting the largest element out of root, left and right child
    if (l < size && arr[l] > arr[largest])
        largest = l;
    if (r < size && arr[r] > arr[largest])
        largest = r;

    // if index of largest element is not root, swap and heapify again
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, largest);
    }
}

void insert(vector<int> &heap, int num)
{
    int size = heap.size();

    // first element
    if (size == 0)
        heap.push_back(num);
    else
    {
        heap.push_back(num);
        for (int i = size / 2 - 1; i >= 0; i--)
            heapify(heap, i);
    }
}

void deleteHeap(vector<int> &heap, int num)
{
    int size = heap.size();

    // search for the element
    int i = 0;
    for (i = 0; i < size; i++)
        if (heap[i] == num)
            break;
    swap(heap[i], heap[size - 1]);
    heap.pop_back();
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(heap, i);
}

int main()
{
    vector<int> heap;
    insert(heap, 4);
    insert(heap, 2);
    insert(heap, 1);
    insert(heap, 5);
    insert(heap, 3);

    cout << heap << endl;

    deleteHeap(heap, 2);

    cout << heap << endl;

    return 0;
}