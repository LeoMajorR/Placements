//Program to print all sentences form given array of words

#include <bits/stdc++.h>
using namespace std;

/*
Input: {{"you", "we"},
        {"have", "are"},
        {"sleep", "eat", "drink"}}

Output:
  you have sleep
  you have eat
  you have drink
  you are sleep
  you are eat
  you are drink
  we have sleep
  we have eat
  we have drink
  we are sleep
  we are eat
  we are drink 
*/

void display(vector<vector<string>> &arr)
{
}

int main()
{
    vector<vector<string>> arr = {{"you", "we"},
                                  {"have", "are"},
                                  {"sleep", "eat", "drink"}};
    display(arr);
    return 0;
}