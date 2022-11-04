#include <bits/stdc++.h>
using namespace std;

bool isDiv7(int arr[], int n)
{
    int twice_unit_digit = 2 * (arr[n - 1]);
    int remaining_part = 0;
    for (int i = 0; i < n - 1; i++)
        remaining_part = remaining_part * 10 + arr[i];
    return ((twice_unit_digit - remaining_part) % 7 == 0);
}

bool isPalindrome(int arr[], int n)
{
    for (int i = 0; i < n / 2; i++)
        if (arr[i] != arr[n - i - 1])
            return false;
    return true;
}
void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i];
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    // first digit 1 and rest 0
    arr[0] = 1;
    for (int i = 1; i < n; i++)
        arr[i] = 0;

    for (int i = 0; i < 7; i++)
    {
        arr[n - 1] = i;
        // if div then break the loop
        if (isDiv7(arr, n))
            break;
    }
    // find the next number div by 7 and palindromic
    while (!isDiv7(arr, n) || !isPalindrome(arr, n))
    {
        // increment the number by 7
        int carry = 7;
        for (int i = n - 1; i >= 0; i--)
        {
            int sum = arr[i] + carry;
            arr[i] = sum % 10;
            carry = sum / 10;
        }
        // display(arr, n);
    }
    display(arr, n);
    return 0;
}