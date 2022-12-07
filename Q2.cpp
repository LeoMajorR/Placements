#include <bits/stdc++.h>
using namespace std;

struct BTreeNode
{
    int val;
    BTreeNode *left;
    BTreeNode *right;
    BTreeNode() : val(0), left(NULL), right(NULL) {}
    BTreeNode(int x) : val(x), left(NULL), right(NULL) {}
    BTreeNode(int x, BTreeNode *left, BTreeNode *right) : val(x), left(left), right(right) {}
    // tree from vector
    BTreeNode(vector<int> &baseTree)
    {
        int n = baseTree.size();
        if (n == 0)
            return;
        val = baseTree[0];
        left = NULL;
        right = NULL;
        queue<BTreeNode *> q;
        q.push(this);
        int i = 1;
        while (i < n)
        {
            BTreeNode *temp = q.front();
            q.pop();
            if (baseTree[i] != -1)
            {
                temp->left = new BTreeNode(baseTree[i]);
                q.push(temp->left);
            }
            i++;
            if (i < n && baseTree[i] != -1)
            {
                temp->right = new BTreeNode(baseTree[i]);
                q.push(temp->right);
            }
            i++;
        }
    }

    // BST from vector
    BTreeNode(vector<int> &baseTree, bool isBST)
    {
        int n = baseTree.size();
        if (n == 0)
            return;
        val = baseTree[0];
        left = NULL;
        right = NULL;
        for (int i = 1; i < n; i++)
        {
            BTreeNode *temp = this;
            while (true)
            {
                if (baseTree[i] < temp->val)
                {
                    if (temp->left == NULL)
                    {
                        temp->left = new BTreeNode(baseTree[i]);
                        break;
                    }
                    else
                    {
                        temp = temp->left;
                    }
                }
                else
                {
                    if (temp->right == NULL)
                    {
                        temp->right = new BTreeNode(baseTree[i]);
                        break;
                    }
                    else
                    {
                        temp = temp->right;
                    }
                }
            }
        }
    }
};

bool checkEquivalence(BTreeNode *a, BTreeNode *b)
{
    if (a == NULL && b == NULL)
        return true;

    if (a != NULL && b != NULL)
    {
        if (a->val == b->val)
        {
            return checkEquivalence(a->left, b->left) && checkEquivalence(a->right, b->right);
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

int depth(BTreeNode *root)
{
    if (root == NULL)
        return 0;
    else
    {
        int lDepth = depth(root->left);
        int rDepth = depth(root->right);

        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
}

int main()
{
    int n;
    cin >> n;

    vector<int> baseTree;
    int temp;
    cin >> temp;
    baseTree.push_back(temp);
    while (temp != -1)
    {
        cin >> temp;
        baseTree.push_back(temp);
    }

    // create tree from array
    BTreeNode *bTree = new BTreeNode(baseTree);

    vector<BTreeNode *> treeVector;

    for (int i = 0; i < n - 1; i++)
    {
        vector<int> tempTree;
        cin >> temp;
        tempTree.push_back(temp);
        while (temp != -1)
        {
            cin >> temp;
            tempTree.push_back(temp);
        }
        BTreeNode *tempNode = new BTreeNode(tempTree, true));
        treeVector.push_back(tempNode);
    }

    // check equivalence of trees
    for (int i = 0; i < n - 1; i++)
    {
        if (checkEquivalence(bTree, treeVector[i]))
            cout << "YES " << depth(bTree) - depth(treeVector[i]) << endl;
        else
            cout << "NO" << depth(bTree) - depth(treeVector[i]) << endl;
    }
}