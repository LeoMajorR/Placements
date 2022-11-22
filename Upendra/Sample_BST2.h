#include <queue>
#include <stack>
#include <iostream>
using namespace std;
#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

template <class T>
class Stack : public stack<T>
{
public:
    T pop()
    {
        T tmp = stack<T>::top();
        stack<T>::pop();
        return tmp;
    }
};

template <class T>
class Queue : public queue<T>
{
public:
    T dequeue()
    {
        T tmp = queue<T>::front();
        queue<T>::pop();
        return tmp;
    }
    void enqueue(const T &el)
    {
        queue<T>::push(el);
    }
};
template <class T>
class BST;

template <class T>
class BSTNode
{
public:
    BSTNode()
    {
        left = right = 0;
    }
    BSTNode(const T &e, BSTNode<T> *l = 0, BSTNode<T> *r = 0)
    {
        el = e;
        left = l;
        right = r;
    }
    T el;
    BSTNode<T> *left, *right;
};

template <class T>
class BST
{
public:
    BST()
    {
        root = 0;
    }
    ~BST()
    {
        clear();
    }
    void clear()
    {
        clear(root);
        root = 0;
    }
    bool isEmpty() const
    {
        return root == 0;
    }
    void preorder()
    {
        preorder(root);
    }
    void inorder()
    {
        inorder(root);
    }
    void postorder()
    {
        postorder(root);
    }
    bool insert(const T &);

    T *search(const T &el)
    {
        return search(root, el);
    }

    int height()
    {
        return height(root);
    }

    int leafCount()
    {
        return leafCount(root);
    }
    void deleteNode(const T &el)
    {
        deleteNode(root, el);
    }

protected:
    BSTNode<T> *root;
    void clear(BSTNode<T> *);
    T *search(BSTNode<T> *, const T &) const;
    void preorder(BSTNode<T> *);
    void inorder(BSTNode<T> *);
    void postorder(BSTNode<T> *);
    virtual void visit(BSTNode<T> *p)
    {
        cout << p->el << ' ';
    }
    int height(BSTNode<T> *);
    int leafCount(BSTNode<T> *);
    void deleteNode(BSTNode<T> *&, const T &);
};

template <class T>
void BST<T>::clear(BSTNode<T> *p)
{
    if (p != 0)
    {
        clear(p->left);
        clear(p->right);
        delete p;
    }
}

template <class T>
int BST<T>::height(BSTNode<T> *p)
{
    if (p == 0)
        return 0;
    int hl = height(p->left);
    int hr = height(p->right);
    if (hl > hr)
        return ++hl;
    else
        return ++hr;
}

// leaf count
template <class T>
int BST<T>::leafCount(BSTNode<T> *p)
{
    if (p == 0)
        return 0;
    if (p->left == 0 && p->right == 0)
        return 1;
    else
        return leafCount(p->left) + leafCount(p->right);
}

template <class T>
int height(BSTNode<T> *p)
{
    if (p == 0)
        return 0;
    int hl = height(p->left);
    int hr = height(p->right);
    if (hl > hr)
        return ++hl;
    else
        return ++hr;
}

template <class T>
bool AVLCheck(BSTNode<T> *root)
{
    if (root == NULL)
        return true;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    if (abs(leftHeight - rightHeight) <= 1 && AVLCheck(root->left) && AVLCheck(root->right))
        return true;
    return false;
}

template <class T>
bool BST<T>::insert(const T &el)
{
    BSTNode<T> *p = root, *prev = 0;
    while (p != 0)
    { // find a place for inserting new node;
        prev = p;
        if (el < p->el)
            p = p->left;
        else
            p = p->right;
    }
    if (root == 0) // tree is empty;
        root = new BSTNode<T>(el);
    else if (el < prev->el)
        prev->left = new BSTNode<T>(el);
    else
        prev->right = new BSTNode<T>(el);
    bool avl = AVLCheck(root);
    if (!avl)
        deleteNode(el);
    return avl;
}

template <class T>
void BST<T>::deleteNode(BSTNode<T> *&p, const T &el)
{
    if (p == 0)
        return; // el is not in tree
    if (el < p->el)
        deleteNode(p->left, el);
    else if (el > p->el)
        deleteNode(p->right, el);
    else
    { // *p is the node to be deleted
        BSTNode<T> *q = p->left;
        BSTNode<T> *r = p->right;
        delete p;
        if (r == 0)
            p = q;
        else
        { // successor is in right subtree
            BSTNode<T> *s = r;
            while (s->left != 0)
                s = s->left;
            s->left = q;
            p = r;
        }
    }
}

template <class T>
T *BST<T>::search(BSTNode<T> *p, const T &el) const
{
    while (p != 0)
        if (el == p->el)
            return &p->el;
        else if (el < p->el)
            p = p->left;
        else
            p = p->right;
    return 0;
}

template <class T>
void BST<T>::inorder(BSTNode<T> *p)
{
    if (p != 0)
    {
        inorder(p->left);
        visit(p);
        inorder(p->right);
    }
}

template <class T>
void BST<T>::preorder(BSTNode<T> *p)
{
    if (p != 0)
    {
        visit(p);
        preorder(p->left);
        preorder(p->right);
    }
}

template <class T>
void BST<T>::postorder(BSTNode<T> *p)
{
    if (p != 0)
    {
        postorder(p->left);
        postorder(p->right);
        visit(p);
    }
}

#endif