#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode (): val(0), next(NULL){}
    ListNode(int x): val(x), next(NULL){}
};

class Solution{
    public:

    /**
     * Algorithm:
     * 1. Create two pointers tempA and tempB
     * 2. Assign tempA to headA and tempB to headB
     * 3. While tempA != tempB
     * 4. If tempA == NULL, assign tempA to headB
     * 5. Else, assign tempA to tempA->next
     * 6. If tempB == NULL, assign tempB to headA
     * 7. Else, assign tempB to tempB->next
     * 8. Return tempA
    */

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
        ListNode *tempA = headA;
        ListNode *tempB = headB;
        while(tempA != tempB){
            tempA = tempA == NULL ? headB : tempA->next;
            tempB = tempB == NULL ? headA : tempB->next;
        }
        return tempA;
    }
};