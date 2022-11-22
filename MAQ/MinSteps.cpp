#include <bits/stdc++.h>
using namespace std;

//(1,1) -> (input1, input2)
// (x,y)->(x,x+y) or (x+y,y)
// return -1 if not possible
int minSteps(int input1, int input2)
{
    int count = 0;
    while (input1 != 0 && input2 != 0)
    {
        if (input1 > input2)
        {
            count += input1 / input2;
            input1 = input1 % input2;
        }
        else
        {
            count += input2 / input1;
            input2 = input2 % input1;
        }
    }
    count--;
    if (input1 > 1 || input2 > 1)
        return -1;
    return count;
}
int main()
{
    cout << minSteps(3, 2) << endl;
    cout << minSteps(2, 2) << endl;
}