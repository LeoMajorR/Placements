#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    // Function to sort the given linked list using Merge Sort.
    Node getMid(Node *head)
    {
        Node *slow = head, *fast = head;
        while (fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return *slow;
    }

    Node *merge(Node *a, Node *b)
    {
        Node *result = NULL;
        if (a == NULL)
            return b;
        if (b == NULL)
            return a;
        if (a->data <= b->data)
        {
            result = a;
            result->next = merge(a->next, b);
        }
        else
        {
            result = b;
            result->next = merge(a, b->next);
        }
        return result;
    }

    Node *mergeSort(Node *head)
    {
        // your code here
        Node *ans = head;
        if (head == NULL || head->next == NULL)
            return head;
        Node *mid = getMid(head);
        Node *left = head;
        Node *right = mid->next;
        mid->next = NULL;
        left = mergeSort(left);
        right = mergeSort(right);
        ans = merge(left, right);
        return ans;
    }
};
