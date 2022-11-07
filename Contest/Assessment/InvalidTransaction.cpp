#include <bits/stdc++.h>
using namespace std;

// transaction = {"name,time(in mins),amount,city","name,time,amount,city",...}
// transaction is invalid when the same name and city is repeated within 60 mins
vector<string> invalidTransaction(vector<string> &transaction)
{
    vector<string> ans;
    unordered_map<string, vector<pair<int, int>>> mp;
    for (int i = 0; i < transaction.size(); i++)
    {
        string name = transaction[i].substr(0, transaction[i].find(','));
        int time = stoi(transaction[i].substr(transaction[i].find(',') + 1, transaction[i].find(',', transaction[i].find(',') + 1) - transaction[i].find(',') - 1));
        int amount = stoi(transaction[i].substr(transaction[i].find(',', transaction[i].find(',') + 1) + 1, transaction[i].find(',', transaction[i].find(',', transaction[i].find(',') + 1) + 1) - transaction[i].find(',', transaction[i].find(',') + 1) - 1));
        string city = transaction[i].substr(transaction[i].find(',', transaction[i].find(',', transaction[i].find(',') + 1) + 1) + 1);
        if (amount > 1000)
            ans.push_back(transaction[i]);
        mp[name].push_back({time, i});
    }
    for (auto it : mp)
    {
        sort(it.second.begin(), it.second.end());
        for (int i = 0; i < it.second.size() - 1; i++)
        {
            if (it.second[i + 1].first - it.second[i].first <= 60)
            {
                string city1 = transaction[it.second[i].second].substr(transaction[it.second[i].second].find(',', transaction[it.second[i].second].find(',', transaction[it.second[i].second].find(',') + 1) + 1) + 1);
                string city2 = transaction[it.second[i + 1].second].substr(transaction[it.second[i + 1].second].find(',', transaction[it.second[i + 1].second].find(',', transaction[it.second[i + 1].second].find(',') + 1) + 1) + 1);
                if (city1 != city2)
                {
                    ans.push_back(transaction[it.second[i].second]);
                    ans.push_back(transaction[it.second[i + 1].second]);
                }
            }
        }
    }
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    return ans;
}