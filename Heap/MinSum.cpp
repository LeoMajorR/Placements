#include <bits/stdc++.h>
using namespace std;

string minSUm(int arr[], int n)
{
    sort(arr, arr + n);
    string s1 = "", s2 = "";
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
            s1 += to_string(arr[i]);
        else
            s2 += to_string(arr[i]);
    }
    string ans="";
    int size = s1.size() > s2.size() ? s1.size() : s2.size();
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    int carry = 0;
    for(int i=0;i<size;i++)
    {
        int a = i<s1.size() ? s1[i]-'0' : 0;
        int b = i<s2.size() ? s2[i]-'0' : 0;
        int sum = a+b+carry;
        carry = sum/10;
        sum = sum%10;
        ans += to_string(sum);
    }
    if(carry)
        ans += to_string(carry);
    reverse(ans.begin(), ans.end());
    //remove leading zeroes
    int i=0;
    while(ans[i]=='0')
        i++;
    return ans.substr(i);
    return ans;
}
int main()
{
    // arr = 1 1 5 2 7 6 1 4 2 3 2 2 1 6 8 5 7 6 1 8 9 2 7 9 5 4 3 1
    int n = 28;
    int arr[] = {1, 1, 5, 2, 7, 6, 1, 4, 2, 3, 2, 2, 1, 6, 8, 5, 7, 6, 1, 8, 9, 2, 7, 9, 5, 4, 3, 1};
    cout << minSUm(arr, n);
}