#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> leftView(TreeNode *root)
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
            if (i == 0)
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
/**
 * @brief 
 * 
 * @param root 
 * @param level : level of the node
 * @param maxLevel  : max level of the node
 * @param ans 
 */
void leftView(TreeNode *root, int level, int &maxLevel, vector<int> &ans)
{
    if (root == NULL)
        return;
    if (maxLevel < level)
    {
        ans.push_back(root->val);
        maxLevel = level;
    }
    leftView(root->left, level + 1, maxLevel, ans);
    leftView(root->right, level + 1, maxLevel, ans);
}

vector<int> leftView(TreeNode *root)
{
    vector<int> ans;
    int maxLevel = 0;
    leftView(root, 1, maxLevel, ans);
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
    vector<int> ans = leftView(root);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    return 0;
}