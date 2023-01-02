#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    bool isSimilar(string &a, string &b)
    {
        int n = a.size();
        int m = b.size();
        vector<bool> str1(26, false);
        vector<bool> str2(26, false);
        for(int i = 0; i < n; i++) {
            str1[a[i] - 'a'] = true;
        }
        for(int i = 0; i < m; i++) {
            str2[b[i] - 'a'] = true;
        }
        for(int i = 0; i < 26; i++) {
            if(str1[i]!= str2[i]) {
                return false;
            }
        }
        return true;
    }

    // two string are similar if they have same characters
    int similarPairs(vector<string> &words)
    {
        int n = words.size();
        int ans = 0;
        for (int i = 0; i < n-1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isSimilar(words[i], words[j])) {
                    ans++;
                    // cout<<words[i]<<" "<<words[j]<<endl;
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<string> words = { "aba", "aabb", "abcd","bac", "aabc" };
    cout << sol.similarPairs(words) << endl;
    return 0;
}