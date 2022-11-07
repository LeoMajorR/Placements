#include <bits/stdc++.h>
using namespace std;


// return string with first non-repeating character for input stream of characters
string FirstNonRepeating(string str)
{
    string ans = "";
    int freq[26] = {0};
    queue<char> q;
    for(int i = 0; i < str.length(); i++){
        q.push(str[i]);
        freq[str[i] - 'a']++;
        while(!q.empty()){
            if(freq[q.front() - 'a'] > 1)
                q.pop();
            else{
                ans += q.front();
                break;
            }
        }
        if(q.empty())
            ans += '#';
    }
    return ans;
}

int main()
{
    string str = "hrqcvsvszpsjammdrw";
    cout << FirstNonRepeating(str);
}