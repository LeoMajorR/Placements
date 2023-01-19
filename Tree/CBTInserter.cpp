#include <bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class CBTINserter
{
    public:
    TreeNode* root;
    CBTINserter(TreeNode* root) {
        this->root = root;
    }

    int insert(int val)
    {
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* temp = q.front();
            q.pop();
            if(temp->left == NULL)
            {
                temp->left = new TreeNode(val);
                return temp->val;
            }
            else if(temp->right == NULL)
            {
                temp->right = new TreeNode(val);
                return temp->val;
            }
            else
            {
                q.push(temp->left);
                q.push(temp->right);
            }
        }
        return -1;
    }

    TreeNode* get_root()
    {
        return root;
    }

};