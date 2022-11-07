#include <bits/stdc++.h>
using namespace std;

int main()
{
    int checkPoinTime;
    cin >> checkPoinTime;
    queue<int> q;
    int serviceTmPrCstmr = 3;
    int currTime = 0;

    // inserting customers in queue till -1 is encountered
    while (1)
    {
        int arrivalTime;
        cin >> arrivalTime;
        if (arrivalTime == -1)
            break;
        if (arrivalTime <= checkPoinTime)
            q.push(arrivalTime);
    }

    while (!q.empty())
    {
        if (checkPoinTime == 0)
        {
            q.pop();
            break;
        }
        if (checkPoinTime < 0)
            break;
        int arrivalTime = q.front();
        q.pop();
        if (currTime >= arrivalTime)
            currTime += serviceTmPrCstmr;
        else
            currTime = arrivalTime + serviceTmPrCstmr;

        checkPoinTime -= serviceTmPrCstmr;
    }
    // dsiplay q elements
    cout << q.size() << " ";
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}
