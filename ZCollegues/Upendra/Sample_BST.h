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
    void insert(const T &);

    T *search(const T &el)
    {
        return search(root, el);
    }

    void findAndDeleteByMerging(const T &);
    {
        findAndDeleteByMerging(root, el);
    }
    void findAndDeleteByCopying(const T &);
    {
        findAndDeleteByCopying(root, el);
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
    void findAndDeleteByMerging(BSTNode<T> *&, const T &);
    void findAndDeleteByCopying(BSTNode<T> *&, const T &);
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
void BST<T>::insert(const T &el)
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

template <class T>
void deleteByMerging(BSTNode<T> *&node)
{
    BSTNode<T> *tmp = node;
    if (node->right == 0)
        node = node->left;
    else if (node->left == 0)
        node = node->right;
    else
    {
        tmp = node->left;
        while (tmp->right != 0)
            tmp = tmp->right;
        tmp->right = node->right;
        tmp = node;
        node = node->left;
    }
    delete tmp;
}

template <class T>
void BST<T>::findAndDeleteByMerging(BSTNode<T> *&p, const T &el)
{
    BSTNode<T> *node = root, *prev = 0;
    while (node != 0)
    {
        if (node->el == el)
            break;
        prev = node;
        if (el < node->el)
            node = node->left;
        else
            node = node->right;
    }
    if (node != 0 && node->el == el)
    {
        if (node == root)
            deleteByMerging(root);
        else if (prev->left == node)
            deleteByMerging(prev->left);
        else
            deleteByMerging(prev->right);
    }
    elseif(root != 0)
            cout
        << "el " << el << " is not in the tree" << endl;
    else cout
        << "the tree is empty" << endl;
}

template <class T>
void BST<T>::findAndDeleteByCopying(BSTNode<T> *&p, const T &el)
{
    if (p == 0)
        return;
    if (el < p->el)
        findAndDeleteByCopying(p->left, el);
    else if (el > p->el)
        findAndDeleteByCopying(p->right, el);
    else
    {
        BSTNode<T> *tmp = p;
        if (p->right == 0)
            p = p->left;
        else if (p->left == 0)
            p = p->right;
        else
        {
            tmp = p->left;
            while (tmp->right != 0)
                tmp = tmp->right;
            tmp->right = p->right;
            tmp = p;
            p = p->left;
        }
        delete tmp;
    }
}
#endif