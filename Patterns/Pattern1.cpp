#include <bits/stdc++.h>
using namespace std;

/**
 * Pattern 1
 *  #
 *  # #
 *  # # #
 *  # # # #
 *  # # # # #
 *
 *  Pattern 3
 *           #
 *         # #
 *       # # #
 *     # # # #
 *   # # # # #
 *  # # # # # #
 *
 */

void pattern1(int n)
{
    cout << "Pattern 1" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << "# ";
        }
        cout << endl;
    }
}
void pattern2(int n)
{
    cout << "Pattern 2" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < i + 1; j++)
        {
            cout << "# ";
        }
        cout << endl;
    }
}
void pattern3(int n)
{
    cout << "Pattern 3" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << "  ";
        }
        for (int j = 0; j < i + 1; j++)
        {
            cout << "# ";
        }
        cout << endl;
    }
}

void diamond(int n)
{
    cout << "Diamond" << endl;
    // upper half
    for (int i = 0; i < n; i++)
    {
        // left half
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << "  ";
        }
        for (int j = 0; j < i + 1; j++)
        {
            cout << "# ";
        }
        for (int j = 0; j < i; j++)
        {
            cout << "# ";
        }
        cout << endl;
    }
    // lower half
    for (int i = n - 1; i >= 0; i--)
    {
        // left half
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << "  ";
        }
        for (int j = 0; j < i + 1; j++)
        {
            cout << "# ";
        }
        for (int j = 0; j < i; j++)
        {
            cout << "# ";
        }
        cout << endl;
    }
}

int main()
{
    int n = 5;
    pattern1(n);
    pattern2(n);
    pattern3(6);
    diamond(n);
    return 0;
}