#include <bits/stdc++.h>
using namespace std;

int main()
{
    int time = -1, ar = 0, te = 0;
    int n, i = 0, f, queue[100];

    while (1)
    {
        scanf("%d", &n);
        if (n == -1)
            break;
        if (time == -1)
        {
            time = n;
        }
        else
        {
            if (n <= time)
            {
                if (te <= time)
                {
                    if (te < n)
                        te = n;
                }
                else
                {
                    queue[i++] = n;
                }
                te = te + 3;
            }
        }
    }

    printf("%d", i);

    for (f = 0; f < i; f++)
    {
        printf(" %d", queue[f]);
    }

    return 0;
}