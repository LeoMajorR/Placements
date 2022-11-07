#include <bits/stdc++.h>
using namespace std;


struct Node
{
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

//segregate LL in odd and even nodes
Node* segregate(Node *head)
{
    Node *odd = NULL, *even = NULL, *oddHead = NULL, *evenHead = NULL;
    while(head != NULL)
    {
        if(head->data % 2 == 0)
        {
            if(even == NULL)
            {
                even = head;
                evenHead = even;
            }
            else
            {
                even->next = head;
                even = even->next;
            }
        }
        else
        {
            if(odd == NULL)
            {
                odd = head;
                oddHead = odd;
            }
            else
            {
                odd->next = head;
                odd = odd->next;
            }
        }
        head = head->next;
    }
    if(even != NULL)
        even->next = NULL;
    if(odd != NULL)
        odd->next = evenHead;
    if(oddHead != NULL)
        return oddHead;
    else
        return evenHead;
}