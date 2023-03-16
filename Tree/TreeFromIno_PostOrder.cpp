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
    TreeNode *buildTree(vector<int> &inorder, int inStart, int inEnd, vector<int> &postorder, int postStart, int postEnd)
    {
        if (inStart > inEnd || postStart > postEnd)
            return NULL;
        int rootVal = postorder[postEnd];
        TreeNode *root = new TreeNode(rootVal);
        int k = 0; // index of rootVal in inorder
        for (int i = inStart; i <= inEnd; i++)
        {
            if (inorder[i] == rootVal)
            {
                k = i;
                break;
            }
        }
        root->left = buildTree(inorder, inStart, k - 1, postorder, postStart, postStart + k - inStart - 1);
        root->right = buildTree(inorder, k + 1, inEnd, postorder, postStart + k - inStart, postEnd - 1);
        return root;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int n = inorder.size();
        if (n == 0)
            return NULL;
        return buildTree(inorder, 0, n - 1, postorder, 0, n - 1);
    }
};
