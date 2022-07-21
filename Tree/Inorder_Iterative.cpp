#include <bits/stdc++.h>
using namespace std;

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &vec)
{
    for (auto elem : vec)
    {
        os << elem << " ";
    }
    return os;
}

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
    vector<int> iterativeInorder(Node *root)
    {
        vector<int> tree_elements;
        stack<Node *> s;
        Node *current = root;
        while (current != NULL || !s.empty())
        {
            while (current != NULL)
            {
                s.push(current);
                current = current->left;
            }
            current = s.top();
            s.pop();
            tree_elements.push_back(current->data);
            current = current->right;
        }
        return tree_elements;
    }
};

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(11);
    root->right->left->left = new Node(12);
    root->right->left->right = new Node(13);
    root->right->right->left = new Node(14);
    root->right->right->right = new Node(15);
    vector<int> tree_elements = root->iterativeInorder(root);
    cout << tree_elements << endl;
    return 0;
}
