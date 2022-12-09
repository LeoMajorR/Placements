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
// goodness of a sequence is defined as bitwise OR of its elements
// given array of integers, find all possible distinct values of goodness that can be obtained by choosing any strictly increasing subsequence of the array
// input = [3,2,4,6]
// output = [0,2,3,4,6,7]
// input = [3,5,5,1]
// output = [0,1,3,5,7]
// input = [5, 4, 6, 1, 1, 5]
// output = [0,1,4,5,6]
vector<int> getDistinctGoodnessValues(vector<int> &arr)
{
    set<int> s;

    // insert 0
    s.insert(0);

    // insert all elements of arr
    for (int i = 0; i < arr.size(); i++)
    {
        s.insert(arr[i]);
    }

    // find strictly increasing subsets
    vector<int> subset;
    vector<vector<int>> subsets;
    for (int i = 0; i < arr.size(); i++)
    {
        subset.push_back(arr[i]);
        subsets.push_back(subset);
        for (int j = i + 1; j < arr.size(); j++)
        {
            subset.push_back(arr[j]);
            subsets.push_back(subset);
        }
        subset.clear();
    }
    // // display subseq
    // for (int i = 0; i < subseq.size(); i++)
    // {
    //     cout << subseq[i] << endl;
    // }
    // find bitwise OR of each subset
    
}

int main()
{
    vector<int> seq = {5, 4, 6, 1, 1, 5};
    vector<int> ans = getDistinctGoodnessValues(seq);
    cout << ans << endl;
}