#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int height(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}
TreeNode *remove(TreeNode *root, int val)
{
    if (root == nullptr)
        return nullptr;
    if (root->val == val)
    {
        if (root->left == nullptr)
            return root->right;
        if (root->right == nullptr)
            return root->left;
        TreeNode *temp = root->right;
        while (temp->left != nullptr)
            temp = temp->left;
        root->val = temp->val;
        root->right = remove(root->right, temp->val);
    }
    else if (root->val > val)
        root->left = remove(root->left, val);
    else
        root->right = remove(root->right, val);
    return root;
}

vector<int> subTreeRemovalQueries(TreeNode *root, vector<int> &queries)
{
    vector<int> ans;
    for (int i = 0; i < queries.size(); i++)
    {
        // remove subtree with root as queries[i]
        TreeNode *temp, *nw;
        temp = root;
        nw = remove(temp, queries[i]);
        ans.push_back(height(nw));
    }
    return ans;
}