#include <bits/stdc++.h>
using namespace std;

// class for Node
class Node
{
public:
    int data;
    int priority;
    Node *next;
    Node(int data, int priority)
    {
        this->data = data;
        this->priority = priority;
        this->next = NULL;
    }
};

// create new Node
Node *newNode(int data, int priority)
{
    Node *temp = new Node(data, priority);
    return temp;
}

Node *head = NULL;

void enqueue(int data, int priority)
{
    Node *temp = newNode(data, priority);

    // base case
    if (head == NULL)
    {
        head = temp;
        return;
    }

    Node *curr = head;
    Node *prev = NULL;

    // search for node with highest priority
    while (curr != NULL && curr->priority > priority)
    {
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL)      // if last node
        prev->next = temp; // add new node at the end
    else
    {
        if (prev == NULL) // insert at beginning
        {
            temp->next = head; // add new node at the beginning
            head = temp;
        }
        else // insert in between
        {
            temp->next = curr; // add new node in between
            prev->next = temp;
        }
    }
}

int dequeue()
{
    if (!head)
        return -1;
    Node *temp = head;
    head = head->next;
    return temp->data;
}

int peek()
{
    if (!head)
        return -1;
    Node *temp = head;
    while (temp->next)
        temp = temp->next;
    return temp->data;
}
void display()
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " " << temp->priority << " " << endl;
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    enqueue(1, 1);
    enqueue(4, 4);
    enqueue(2, 2);
    enqueue(5, 5);
    enqueue(3, 3);
    enqueue(6, 6);

    peek();
    display();

    dequeue();
    display();

    dequeue();
    display();

    return 0;
}