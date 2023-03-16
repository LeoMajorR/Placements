#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *head = NULL, *tail = NULL;
        priority_queue<pair<int, ListNode *>, vector<pair<int, ListNode *>>, greater<pair<int, ListNode *>>> pq;
        for (auto node : lists)
            if (node != NULL)
                pq.push({node->val, node});
        while (!pq.empty())
        {
            auto node = pq.top();
            pq.pop();
            if (head == NULL) // if head is NULL, then assign head and tail to the first node
                head = tail = node.second;
            else // else, assign tail->next to the node and move tail to the next node
            {
                tail->next = node.second;
                tail = tail->next;
            }
            if (node.second->next != NULL) // if the node has a next node, push it to the priority queue
                pq.push({node.second->next->val, node.second->next});
        }
        return head;
    }
};
