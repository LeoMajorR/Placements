#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

int ans = 0;

void dfs(TreeNode* root, int minVal, int maxVal){
    if(root == NULL)
        return;
    ans = max(ans, max(abs(root->val - minVal), abs(root->val - maxVal)));
    minVal = min(minVal, root->val);
    maxVal = max(maxVal, root->val);
    dfs(root->left, minVal, maxVal);
    dfs(root->right, minVal, maxVal);
}

int maxAncestorDiff(TreeNode *root)
{
    dfs(root, root->val, root->val);
    return ans;
}