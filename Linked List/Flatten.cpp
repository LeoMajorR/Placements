#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *bottom;

    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

Node *merge(Node *a, Node *b)
{
    if (a == NULL)
        return b;
    if (b == NULL)
        return a;

    Node *result;

    if (a->data < b->data)
    {
        result = a;
        result->bottom = merge(a->bottom, b);
    }
    else
    {
        result = b;
        result->bottom = merge(a, b->bottom);
    }

    result->next = NULL;
    return result;
}

Node *flattenLL(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    head->next = flattenLL(head->next);

    Node *res = merge(head, head->next);

    return res;
}

int main()
{
    Node *head = new Node(5);
    head->next = new Node(10);
    head->next->next = new Node(19);
    head->next->next->next = new Node(28);

    head->bottom = new Node(7);
    head->bottom->bottom = new Node(8);
    head->bottom->bottom->bottom = new Node(30);

    head->next->bottom = new Node(20);

    head->next->next->bottom = new Node(22);
    head->next->next->bottom->bottom = new Node(50);

    head->next->next->next->bottom = new Node(35);
    head->next->next->next->bottom->bottom = new Node(40);
    head->next->next->next->bottom->bottom->bottom = new Node(45);

    //display the linked list
    Node *temp = head;
    while (temp != NULL)
    {
        Node *temp1 = temp;
        while (temp1 != NULL)
        {
            cout << temp1->data << " ";
            temp1 = temp1->bottom;
        }
        temp = temp->next;
        cout << endl;
    }

    Node *res = flattenLL(head);

    while (res != NULL)
    {
        cout << res->data << " ";
        res = res->bottom;
    }

    return 0;
}