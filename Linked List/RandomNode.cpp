#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *head;
    Solution(ListNode *head)
    {
        this->head = head;
    }
    int getRandom()
    {
        ListNode *curr = head;
        int res = 0, count = 0;
        while (curr != NULL)
        {
            count++;
            if (rand() % count == 0)
                res = curr->val;
            curr = curr->next;
        }
        return res;
    }
};
