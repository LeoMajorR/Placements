#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *left, *right, *next;
    Node(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution
{
public:
    Node *connect(Node *root)
    {
        if (root == NULL)
            return NULL;
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            int n = q.size();
            Node *prev = NULL;
            for (int i = 0; i < n; i++)
            {
                Node *curr = q.front();
                q.pop();
                if (prev != NULL)
                    prev->next = curr;
                prev = curr;
                if (curr->left != NULL)
                    q.push(curr->left);
                if (curr->right != NULL)
                    q.push(curr->right);
            }
        }
        return root;
    }
};
