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

int main()
{
    int v = 6;
    vector<vector<int>> graph(v);
    for (int i = 0; i < v - 2; i++)
    {
        graph[i].push_back(i + 1);
        graph[i].push_back(i + 2);
        graph[i].push_back(i + 3);
    }
    cout << graph << endl;
    return 0;
}