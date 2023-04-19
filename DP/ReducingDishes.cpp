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

class Solution
{
public:
    int maxSatisfaction(vector<int> &satisfaction)
    {
        vector<int> dp(satisfaction.size() + 1, 0);
        }
};

int main()
{
    Solution s;
    vector<int> satisfaction = {-1, -8, 0, 5, -9};
    cout << s.maxSatisfaction(satisfaction);
    return 0;
}
