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


Node *sortLLof012(Node *head)
{
    int count[3] = {0, 0, 0};
    Node *ptr = head;

    while (ptr != NULL)
    {
        count[ptr->data] += 1;
        ptr = ptr->next;
    }

    int i = 0;
    ptr = head;

    while (ptr != NULL)
    {
        if (count[i] == 0)
            i++;
        else
        {
            ptr->data = i;
            --count[i];
            ptr = ptr->next;
        }
    }
    return head;
}