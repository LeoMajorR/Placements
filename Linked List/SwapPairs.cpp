#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode (): val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    ListNode *swapPpairs(ListNode *head}
    {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *cur = dummy;
        while (cur->next && cur->next->next) {
            ListNode *tmp = cur->next->next;
            cur->next->next = tmp->next;
            tmp->next = cur->next;
            cur->next = tmp;
            cur = cur->next->next;
        }
        return dummy->next;
    }
};


