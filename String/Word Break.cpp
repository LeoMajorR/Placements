#include <bits/stdc++.h>
using namespace std;

//Approach-1: Memoization DP
class Solution
{
    unordered_map<int, bool> mem;
    unordered_set<string> myset; //dictionary
    bool partition(string s, int pos)
    {
        if (pos == s.size())
            return true;
        if (mem.count(pos))
            return mem[pos];

        string t = "";
        for (int i = pos; i < s.size(); ++i)
            if (myset.count(s.substr(pos, i - pos + 1)) and partition(s, i + 1))
                return mem[pos] = true;
        return mem[pos] = false;
    }

public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        for (auto str : wordDict)
            myset.insert(str);

        return partition(s, 0);
    }
};

//Approach-2: Tabulation DP
class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        int n = s.size();
        bool dp[n + 1][n + 1];

        unordered_set<string> myset;
        for (auto word : wordDict)
            myset.insert(word);

        for (int length = 1; length <= n; ++length) //Window Size
        {
            int start = 1;
            int end = length;
            while (end <= n) //Sliding Window
            {
                string temp = s.substr(start - 1, length);
                if (myset.find(temp) != myset.end())
                    dp[start][end] = true;
                else
                {
                    bool flag = false;
                    for (int i = start; i < end; ++i)
                        if (dp[start][i] and dp[i + 1][end])
                        {
                            flag = true;
                            break;
                        }
                    dp[start][end] = flag;
                }
                start += 1;
                end += 1;
            }
        }
        return dp[1][n];
    }
};

//Approach-3: BFS
class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        queue<int> q;               //Store start position for each new search query
        q.push(0);                  //We must start from pos 0
        unordered_set<int> visited; //Keeps already processed positions
        unordered_set<string> dict; //wordDict set

        //Store wordDict in dict-set for easy search
        for (string it : wordDict)
            dict.insert(it);

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();

            if (!visited.count(curr))
            { //Don't re-process a pos
                visited.insert(curr);
                string temp = "";
                for (int start = curr; start < s.size(); ++start)
                {
                    temp.push_back(s[start]);
                    if (dict.count(temp))
                    {
                        q.push(start + 1);
                        if (start == s.size() - 1)
                            return true;
                    }
                }
            }
        }
        return false;
    }
};