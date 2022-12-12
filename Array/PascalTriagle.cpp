#include <bits/stdc++.h>
using namespace std;


template <typename T>
std::ostream & operator << (std::ostream & os, const std::vector<T> & vec)
{
    for(auto elem : vec)
    {
        os<<elem<< " ";
    }
    return os;
}
vector<int> getRow(int rowInd)
{
    vector<int> result;
    for (int i = 0; i <= rowInd; i++)
    {
        result.push_back(1);
        for (int j = i - 1; j > 0; j--)
        {
            result[j] = result[j] + result[j - 1];
        }
        cout<<result<<endl;
    }
    return result;
}

int main()
{
    vector<int> result = getRow(3);
    return 0;
}