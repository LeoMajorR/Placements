#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> topView(TreeNode *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    queue<pair<TreeNode *, int>> q;
    map<int, int> m;
    q.push({root, 0});
    while (!q.empty())
    {
        TreeNode *temp = q.front().first;
        int hd = q.front().second;
        q.pop();
        if (m.find(hd) == m.end())
            m[hd] = temp->val;
        if (temp->left != NULL)
            q.push({temp->left, hd - 1});
        if (temp->right != NULL)
            q.push({temp->right, hd + 1});
    }
    for (auto it : m)
        ans.push_back(it.second);
    return ans;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->left->right->right = new TreeNode(5);
    root->left->right->right->right = new TreeNode(6);
    vector<int> ans = topView(root);
    for (int i : ans)
        cout << i << " ";
    return 0;
}