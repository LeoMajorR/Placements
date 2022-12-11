#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {}
};

bool leafSimilar(TreeNode *root)
{
    vector<int> v1, v2;
    stack<TreeNode *> s;
    s.push(root);
    while (!s.empty())
    {
        TreeNode *temp = s.top();
        s.pop();
        if (temp->left == nullptr && temp->right == nullptr)
            v1.push_back(temp->val);
        if (temp->right)
            s.push(temp->right);
        if (temp->left)
            s.push(temp->left);
    }
    s.push(root);
    while (!s.empty())
    {
        TreeNode *temp = s.top();
        s.pop();
        if (temp->left == nullptr && temp->right == nullptr)
            v2.push_back(temp->val);
        if (temp->left)
            s.push(temp->left);
        if (temp->right)
            s.push(temp->right);
    }
    return v1 == v2;
}