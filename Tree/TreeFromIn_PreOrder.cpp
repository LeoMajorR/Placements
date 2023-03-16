#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *buildTree(vector<int> &inOrder, int inStart, int inEnd, vector<int> &preOrder, int preStart, int preEnd)
    {
        if (inStart > inEnd || preStart > preEnd)
            return NULL;
        int rootVal = preOrder[preStart];
        TreeNode *root = new TreeNode(rootVal);
        int k = 0; // index of rootVal in inorder
        for (int i = inStart; i <= inEnd; i++)
        {
            if (inOrder[i] == rootVal)
            {
                k = i;
                break;
            }
        }
        root->left = buildTree(inOrder, inStart, k - 1, preOrder, preStart + 1, preStart + k - inStart);
        root->right = buildTree(inOrder, k + 1, inEnd, preOrder, preStart + k - inStart + 1, preEnd);
        return root;
    }

    TreeNode *buildTree(vector<int> &inOrder, vector<int> &preOrder)
    {
        int n = inOrder.size();
        if (n == 0)
            return NULL;
        return buildTree(inOrder, 0, n - 1, preOrder, 0, n - 1);
    }
};
