#include <bits/stdc++.h>
using namespace std;

int CountLETTER(string str)
{
    int count = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (isalpha(str[i]))
            count++;
    }
    return count;
}

int CountDIGIT(string str)
{
    int count = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (isdigit(str[i]))
            count++;
    }
    return count;
}

int main()
{
    // input string
    string str;
    // cin >> str;
    str = "az$6";
    cout<<CountLETTER(str)<<endl;
    cout<<CountDIGIT(str);
    return 0;
}