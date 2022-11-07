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

// original array from prefix xor
vector<int> prefixXOR(vector<int> &prefix)
{
    vector<int> arr;
    arr.push_back(prefix[0]);
    for (int i = 1; i < prefix.size(); i++)
    {
        arr.push_back(prefix[i] ^ prefix[i - 1]);
    }
    return arr;
}

int main()
{
    vector<int> prefix = {5, 2, 0, 3, 1};
    vector<int> arr = prefixXOR(prefix);
    cout << "Original array: " << arr << endl;
    return 0;
}