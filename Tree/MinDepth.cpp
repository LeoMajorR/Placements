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
    int minDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        if (root->left == NULL && root->right == NULL)
            return 1;
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        if (left == 0)
            return right + 1;
        if (right == 0)
            return left + 1;
        return min(left, right) + 1;
    }
};
