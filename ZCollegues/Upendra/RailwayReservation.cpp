#include <bits/stdc++.h>
using namespace std;

int minCounters(vector<int> custPerMin, vector<int> serveTime)
{
    vector<int> queue(1, 0);
    for (int i = 0; i < 86400; i++)
    {
        int no_of_customers = custPerMin[1 + (rand() % 99)];
        for (int j = 0; j < no_of_customers; j++)
        {
            int time = serveTime[1 + (rand() % 99)];
            bool flag = false;
            for (int k = 0; k < queue.size(); k++)
            {
                if (queue[k] < 600)
                {

                    queue[k] += time;
                    flag = true;
                    break;
                }
            }
            if (!flag)
            {
                queue.push_back(time);
            }
        }
        for (int k = 0; k < queue.size(); k++)
        {
            if (queue[k] > 60)
                queue[k] -= 60;
            else
                queue[k] = 0;
        }
    }
    return queue.size();
}

void calCustPerMin(vector<int> &custPerMin)
{
    for (int i = 0; i < 101; i++)
    {
        if (i <= 15)
            custPerMin[i] = 0;
        else if (i <= 35)
            custPerMin[i] = 1;
        else if (i <= 60)
            custPerMin[i] = 2;
        else if (i <= 70)
            custPerMin[i] = 3;
        else if (i <= 100)
            custPerMin[i] = 4;
    }
}

void calServeTime(vector<int> &serveTime)
{
    for (int i = 0; i < 101; i++)
    {
        if (i <= 10)
            serveTime[i] = 30;
        else if (i <= 15)
            serveTime[i] = 40;
        else if (i <= 25)
            serveTime[i] = 50;
        else if (i <= 35)
            serveTime[i] = 60;
        else if (i <= 50)
            serveTime[i] = 80;
        else if (i <= 75)
            serveTime[i] = 90;
        else if (i <= 85)
            serveTime[i] = 100;
        else if (i <= 100)
            serveTime[i] = 110;
    }
}

int main()
{
    vector<int> custPerMin(101, 0);
    calCustPerMin(custPerMin);

    vector<int> serveTime(100, 0);
    calServeTime(serveTime);

    cout << "Railway counters required: " << minCounters(custPerMin, serveTime);
    return 0;
}