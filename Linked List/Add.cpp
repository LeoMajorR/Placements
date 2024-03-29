#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
    public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *ans = new ListNode();
        ListNode *ptr = ans;
        int sum=0, carry=0;
        while(l1 || l2 || carry)
        {
            sum=0;
            if(l1)
            {
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2)
            {
                sum+=l2->val;
                l2=l2->next;
            }
            sum+=carry;
            carry=sum/10;
            ptr->next = new ListNode(sum%10);
            ptr=ptr->next;
        }
        return ans->next;
    }
};