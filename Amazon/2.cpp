#include <bits/stdc++.h>
using namespace std;

// aggregate temp change on each day
int getMaxAggregateTemperatureChange(vector<int> tempChange)
{
    vector<int> sum;
    for (auto i : tempChange)
    {
        if (sum.empty())
        {
            sum.push_back(i);
        }
        else
        {
            sum.push_back(sum.back() + i);
        }
    }

    int aggretateTempChange = 0;

    for (int i = 0; i < sum.size(); i++)
    {
        for (int j = i; j < sum.size(); j++)
        {
            int temp = sum[j] - sum[i] + tempChange[i];
            if (temp > aggretateTempChange)
            {
                aggretateTempChange = temp;
            }
        }
    }
    return aggretateTempChange;
}

int main()
{
    vector<int> tempChange = {6, -2, 5};
    cout << getMaxAggregateTemperatureChange(tempChange) << endl;
}