#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(TreNode *root, int &ans, int left, int right)
    {
        if (!root)
            return;
        ans = max(ans, max(left, right));
        dfs(root->left, ans, right + 1, 0);
        dfs(root->right, ans, 0, left + 1);
    }

    int longestZigZag(TreNode *root)
    {
        int ans = 0;
        dfs(root, ans, 0, 0);
        return ans;
    }
};
