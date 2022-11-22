#include <bits/stdc++.h>
using namespace std;

vector<int> reverse(vector<int> &arr, vector<vector<int>> operations)
{
    int n = arr.size();
    for (int i = 0; i < operations.size(); i++)
    {
        int l = operations[i][0];
        int r = operations[i][1];
        if(l==r) continue;
        reverse(arr.begin() + l, arr.begin() + r + 1);
    }
    return arr;
    //regex to check if given string is of length 1 or first and last character is same
    regex reg ("^.{1}$|^(.).*\\1$");
    regex reg("^(.)(.)\\2\\1$");
    regex reg("^(.).*\\1$"); 
    regex re("(.)\\1*");
}

