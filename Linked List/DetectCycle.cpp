#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
    public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *slow, *fast;
        slow = fast = head;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
                break;
        }
        if(!fast || !fast->next) 
            return NULL;

        //cycle detected
        slow = head;
        while(slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};