#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *top;

void push(int data)
{
    Node *newNode = new Node;
    if (!newNode)
    {
        cout << "Stack Overflow" << endl;
        return;
    }
    newNode->data = data;
    newNode->next = top;
    top = newNode;
}

bool isEmpty()
{
    return top == NULL;
}

void pop()
{
    if (isEmpty())
    {
        cout << "Stack Underflow" << endl;
        return;
    }
    Node *temp = top;
    cout << "Popped element is " << temp->data << endl;
    top = top->next;
    delete temp;
}

void peek()
{
    if (isEmpty())
    {
        cout << "Stack Underflow" << endl;
        return;
    }
    cout << "Top element is " << top->data << endl;
}

void display()
{
    if (isEmpty())
    {
        cout << "Stack is empty" << endl;
        return;
    }
    Node *temp = top;
    cout << "Stack elements are: ";
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    push(1);
    push(2);
    push(3);
    push(4);
    display();
    pop();
    peek();
    display();
    return 0;
}