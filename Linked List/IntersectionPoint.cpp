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

// intersection point of Y shaped linked list
int intersectionPoint(Node* head1, Node* head2)
{
    Node* curr1 = head1;
    Node* curr2 = head2;
    int c1 = 0, c2 = 0;
    // count the number of nodes in both linked list
    while (curr1 != NULL)
    {
        c1++;
        curr1 = curr1->next;
    }
    while (curr2 != NULL)
    {
        c2++;
        curr2 = curr2->next;
    }
    int d = abs(c1 - c2);
    // move the pointer of the longer linked list by d nodes
    if (c1 > c2)
    {
        while (d--)
        {
            head1 = head1->next;
        }
    }
    else
    {
        while (d--)
        {
            head2 = head2->next;
        }
    }
    // move both pointers until they are equal
    while (head1 != NULL && head2 != NULL)
    {
        if (head1 == head2)
        {
            return head1->data;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    return -1;
}