#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void add(Node *root, int data)
{
    if (root == NULL)
    {
        root = newNode(data);
        return;
    }
    if (data <= root->data)
    {
        if (root->left == NULL)
            root->left = newNode(data);
        else
            add(root->left, data);
    }
    else
    {
        if (root->right == NULL)
            root->right = newNode(data);
        else
            add(root->right, data);
    }
}