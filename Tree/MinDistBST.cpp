#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    void inorder(TreeNode *root, int &prev, int &minDiff)
    {
        if (root == NULL)
            return;
        inorder(root->left, prev, minDiff);
        if (prev != -1)
            minDiff = min(minDiff, root->val - prev); //
        prev = root->val;
        inorder(root->right, prev, minDiff);
    }
    int minDiffInBST(TreeNode *root)
    {
        int minDiff = INT_MAX;
        int prev = -1;
        inorder(root, prev, minDiff);
        return minDiff;
    }
};
