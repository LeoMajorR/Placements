#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// iterative approach
vector<int> rightViewIterative(TreeNode *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            TreeNode *temp = q.front();
            q.pop();
            if (i == n - 1)
                ans.push_back(temp->val);
            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
        }
    }
    return ans;
}

// recursive approach
void rightView(TreeNode *root, int level, int &maxLevel, vector<int> &ans)
{
    if (root == NULL)
        return;
    if (maxLevel < level)
    {
        ans.push_back(root->val);
        maxLevel = level;
    }
    rightView(root->right, level + 1, maxLevel, ans);
    rightView(root->left, level + 1, maxLevel, ans);
}

vector<int> rightView(TreeNode *root)
{
    vector<int> ans;
    int maxLevel = 0;
    rightView(root, 1, maxLevel, ans);
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
    vector<int> ans = rightViewIterative(root);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    return 0;
}