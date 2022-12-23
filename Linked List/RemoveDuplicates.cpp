#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode (): val(0), next(NULL) {}
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
  //delete nodes with duplicate
  ListNode *deleteDuplicates(ListNode *head)
  {
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *cur = dummy;
    while (cur->next && cur->next->next) {
      if (cur->next->val == cur->next->next->val) {
        int x = cur->next->val;
        while (cur->next && cur->next->val == x) {
          cur->next = cur->next->next;
        }
      } else {
        cur = cur->next;
      }
    }
    return dummy->next; 
  }
};

