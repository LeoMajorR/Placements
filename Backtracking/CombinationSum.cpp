#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    void backtrack(vector<int> &candidates, int target, vector<vector<int>> &res, vector<int> &temp, int start)
    {
        if (target < 0)
            return;
        if (target == 0) {
            res.push_back(temp);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            temp.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], res, temp, i);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> res;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, res, temp, 0);
        return res;
    }
};

