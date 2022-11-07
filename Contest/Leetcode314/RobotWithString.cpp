#include <bits/stdc++.h>
using namespace std;

// lexigraphically smallest string
// allowed operations :
// Remove the first character of a string s and give it to the robot. The robot will append this character to the string t.
// Remove the last character of a string t and give it to the robot.The robot will write this character on paper.
string robotWithString(string s)
{
    stack<char> t;
    string res = "";
    
}

int main()
{
    string s1 = "zza";
    string s2 = "bac";
    string s3 = "bdda";
    cout << robotWithString(s1) << endl;
    cout << robotWithString(s2) << endl;
    cout << robotWithString(s3) << endl;
    return 0;
}