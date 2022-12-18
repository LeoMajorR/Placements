#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int data;
    struct ListNode *next;
    ListNode(int x)
    {
        data = x;
        next = NULL;
    }
    ListNode()
    {
        data = 0;
        next = NULL;
    }
};
ListNode *removeNthNodeFromEnd(ListNode *head, int n)
{
    ListNode *temp = head;
    int len = 0;
    while (temp)
    {
        temp = temp->next;
        len++;
    }

    int k = len - n + 1;
    if (k == 1)
    {
        head = head->next;
        return head;
    }
    temp = head;
    for (int i = 1; i < k - 1; i++)
        temp = temp->next;
    temp->next = temp->next->next;
    return head;
}

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head = removeNthNodeFromEnd(head, 2);
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    return 0;
}