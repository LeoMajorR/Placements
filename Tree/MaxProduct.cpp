#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Max Product of splitted binary tree
*/

struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {}
};

int maxProduct(TreeNode *root)
{
    
}