#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *lca(TreeNode *root, int v1, int v2)
{
    if (root == NULL)
        return NULL;
    if (root->val == v1 || root->val == v2)
        return root;
    TreeNode *left = lca(root->left, v1, v2);
    TreeNode *right = lca(root->right, v1, v2);
    if (left != NULL && right != NULL)
        return root;
    if (left != NULL)
        return left;
    if (right != NULL)
        return right;
    return NULL;
}