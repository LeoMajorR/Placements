#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
// 5->6->7->2->1->NULL

void display(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}
Node *deleteNodeWithGtrRgtVal(Node *head)
{
    // reverse the list
    Node *prev = NULL;
    Node *curr = head;
    Node *next = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    display(prev);

    // traverse the list
    Node *temp = prev;
    int max = temp->data;
    while (temp->next != NULL)
    {
        if (temp->next->data < max)
        {
            temp->next = temp->next->next;
        }
        else
        {
            max = temp->next->data;
            temp = temp->next;
        }
    }

    display(prev);

    Node *prev1 = NULL;
    Node *curr1 = prev;
    Node *next1 = NULL;
    while (curr1 != NULL)
    {
        next1 = curr1->next;
        curr1->next = prev1;
        prev1 = curr1;
        curr1 = next1;
    }
    // display(prev1);
    return prev1;
}
int main()
{
    // 12->15->10->11->5->6->2->3->NULL
    Node *head = new Node(12);
    head->next = new Node(15);
    head->next->next = new Node(10);
    head->next->next->next = new Node(11);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(2);
    head->next->next->next->next->next->next->next = new Node(3);

    Node *temp = deleteNodeWithGtrRgtVal(head);
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    return 0;
}