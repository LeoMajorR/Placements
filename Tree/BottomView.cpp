#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> bottomView(TreeNode *root) {
    vector<int> ans;
    if (!root) return ans;
    map<int, int> mp;
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});
    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        mp[p.second] = p.first->val;
        if (p.first->left) q.push({p.first->left, p.second - 1});
        if (p.first->right) q.push({p.first->right, p.second + 1});
    }
    for (auto p : mp) ans.push_back(p.second);
    return ans;
}   