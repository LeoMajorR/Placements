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
int slotWheels(vector<string> history, int n)
{
    int sum = 0;
    // conver to vector of vector of int
    vector<vector<int>> spinInt;
    for (int i = 0; i < history.size(); i++)
    {
        vector<int> temp;
        for (int j = 0; j < history[i].size(); j++)
        {
            temp.push_back(history[i][j] - '0');
        }
        spinInt.push_back(temp);
    }
    for (int i = 0; i < spinInt.size(); i++)
    {
        sort(spinInt[i].begin(), spinInt[i].end());
    }

    while (spinInt[0].size() > 0)
    {
        int max = 0;
        for (int i = 0; i < spinInt.size(); i++)
        {
            if (spinInt[i][spinInt[i].size() - 1] > max)
            {
                max = spinInt[i][spinInt[i].size() - 1];
            }
        }
        sum += max;
        for (int i = 0; i < spinInt.size(); i++)
        {
            spinInt[i].pop_back();
        }
    }
    return sum;
}

int slotWheels1(vector<string> history, int n)
{
    int sum = 0;
    // conver to vector of vector of int
    vector<vector<int>> spinInt;
    for (int i = 0; i < history.size(); i++)
    {
        vector<int> temp;
        for (int j = 0; j < history[i].size(); j++)
        {
            temp.push_back(history[i][j] - '0');
        }
        spinInt.push_back(temp);
    }
    for (int i = 0; i < spinInt.size(); i++)
    {
        sort(spinInt[i].begin(), spinInt[i].end());
    }

    int n = spinInt.size();
}

int main()
{
    int n = 4;
    vector<string> spins = {"712", "246", "365", "312"};
    vector<string> spins1 = {"1112", "1111", "1211", "1111"};
    int ans = slotWheels(spins, n);
    cout << slotWheels(spins1, n) << endl;
    cout << ans << endl;
}