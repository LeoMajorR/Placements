#include <bits/stdc++.h>
using namespace std;

// int main()
// {
//     int n = 24;
//     int l = 0, r = 100;
//     int ans = n;
//     while (l <= r)
//     {
//         int mid = (l + r) / 2;
//         if (mid * mid <= n)
//         {
//             ans = mid;
//             l = mid + 1;
//         }
//         else
//         {
//             r = mid - 1;
//         }
//     }
//     cout << ans << endl;
// }

void solve()
{
    int n = 24;

    int l = 0, r = 100, ans = n;

    while (l <= r)
    {

        int mid = (l + r) / 2;

        if (mid * mid <= n)
        {

            ans = mid;

            l = mid + 1;
        }

        else
        {

            r = mid - 1;
        }
    }

    cout << ans << endl;
}

int main()
{
    solve();
    return 0;
}