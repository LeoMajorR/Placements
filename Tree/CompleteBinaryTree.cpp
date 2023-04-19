#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * @approach: Level Order Traversal
 * @time: O(N)
 * @space: O(N)
 */

class Solution
{
public:
    bool isCompleteBinaryTree(TreeNode *root)
    {
        if (root == NULL)
            return true;
        queue<TreeNode *> q;
        q.push(root);
        bool flag = false;
        while (!q.empty())
        {
            TreeNode *temp = q.front();
            q.pop();
            if (temp->left)
            {
                if (flag == true)
                    return false;
                q.push(temp->left);
            }
            else
            {
                flag = true;
            }
            if (temp->right)
            {
                if (flag == true)
                    return false;
                q.push(temp->right);
            }
            else
            {
                flag = true;
            }
        }
        return true;
    }
};
