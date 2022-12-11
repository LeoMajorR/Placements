#include <bits/stdc++.h>
using namespace std;

int maximumValue(vector<string> &strs)
{
    bool letters, digits;
    int n = strs.size();
    int mx = INT_MIN;
    for(int i = 0; i < n; i++)
    {
        int len = strs[i].length();
        letters = digits = false;
        for(int j = 0; j < len; j++)
        {
            if(isalpha(strs[i][j]))
                letters = true;
            else if(isdigit(strs[i][j])){
                digits = true;
                if(!letters) mx = max(mx, strs[i][j]-'0');
            }
        }
        if(letters && digits)
            mx = max(mx, len);
        else if(letters)
            mx = max(mx, len);
        else
            mx = max(mx, stoi(strs[i]));
    }
    return mx;
}

int main()
{
    vector<string> str = {"alic3","bob","3","4","00000"};
    vector<string> str1 = {"1","01","001","0001"};
    cout << maximumValue(str);
    cout << maximumValue(str1);
}