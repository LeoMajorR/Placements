#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool find(TreeNode *root, int val, string &path)
{
    if (root->val == val)
        return true;
    if (root->left && find(root->left, val, path))
        path.push_back('L');
    else if (root->right && find(root->right, val, path))
        path.push_back('R');
    return !path.empty();
}

string getDirections(TreeNode *root, int startValue, int destValue)
{
    string r_s, r_d;
    find(root, startValue, r_s);
    find(root, destValue, r_d);
    while (!r_s.empty() && !r_d.empty() && r_s.back() == r_d.back())
        r_s.pop_back(), r_d.pop_back();
    cout << cout << r_d << endl;
    return string(r_s.size(), 'U') + string(rbegin(r_d), rend(r_d));
}

int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(4);
    root->left->left = new TreeNode(3);

    cout << getDirections(root, 3, 6);
}