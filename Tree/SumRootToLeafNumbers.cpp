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
    void sumNumbers(TreeNode *root, int num, int &sum)
    {
        if (root == NULL)
            return;
        num = num * 10 + root->val;
        if (root->left == NULL && root->right == NULL)
        {
            sum += num;
            return;
        }
        sumNumbers(root->left, num, sum);
        sumNumbers(root->right, num, sum);
    }

    int sumNumbers(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int sum = 0;
        sumNumbers(root, 0, sum);
        return sum;
    }
};
