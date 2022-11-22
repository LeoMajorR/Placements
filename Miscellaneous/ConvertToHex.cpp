#include <bits/stdc++.h>
using namespace std;

// a-f lowercase
char *toHex(int n)
{
    char *hex = new char[100];
    int i = 0;
    while (n != 0)
    {
        int temp = 0;
        temp = n % 16;
        if (temp < 10)
        {
            hex[i] = temp + 48;
            i++;
        }
        else
        {
            hex[i] = temp + 87;
            i++;
        }
        n = n / 16;
    }
    hex[i] = '\0';
    // reverse hex
    int j = 0;
    int k = i - 1;
    while (j < k)
    {
        char temp = hex[j];
        hex[j] = hex[k];
        hex[k] = temp;
        j++;
        k--;
    }
    return hex;
}
int main()
{
    int n = 99;
    // cin >> n;
    cout << toHex(n);
    cout << toHex(26);
    return 0;
}
