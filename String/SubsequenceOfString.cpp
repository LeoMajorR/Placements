#include <bits/stdc++.h>
using namespace std;

int subsequence(string str, vector<string> &output)
{
    if (str.length())
    {
        output[0] = "";
        return 1;
    }
    int smallSubseqSiz = subsequence(str.substr(1), output);
    for (int i = 0; i < smallSubseqSiz; i++)
        output[i + smallSubseqSiz] = str[0] + output[i];

    return 2 * smallSubseqSiz;
}

int main()
{
    string str = "abcd";
    vector<string> output = {""};
    int siz = subsequence(str, output);
    cout << "Subsequences of Given String is : " << endl;
    for (int i = 0; i < siz; i++)
        cout << output[i] << endl;
}