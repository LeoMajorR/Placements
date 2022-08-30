#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

struct Node* createNode(int data) {
    struct Node* newNode = new Node;
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
};

void inorder(struct Node* root, vector<int>& v) {
    if (root == NULL) return;
    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

void BSTMaxHeapUtil(struct Node* root, vector<int> &arr, int *i) {
    if(root == NULL) return;

    BSTMaxHeapUtil(root->left, arr, i);
    BSTMaxHeapUtil(root->right, arr, i);
    root->data = arr[*i];
    (*i)++;
}

void BST_to_MaxHeap(struct Node* root) {
    vector<int> arr;

    // perform inorder traversal and store the values in an array
    inorder(root, arr);
    int n = arr.size();

    //perform postOrder and copy values of arr to nodes

    int i = 0;
    BSTMaxHeapUtil(root, arr, &i);
}

void preOrder(struct Node* root) {
    if(root == NULL) return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int main()
{
    struct Node* root = createNode(4);
    root->left = createNode(2);
    root->right = createNode(6);
    root->left->left = createNode(1);
    root->left->right = createNode(3);
    root->right->left = createNode(5);
    root->right->right = createNode(7);

    BST_to_MaxHeap(root);

    cout << "Max Heap: ";
    preOrder(root);

    return 0;
}
