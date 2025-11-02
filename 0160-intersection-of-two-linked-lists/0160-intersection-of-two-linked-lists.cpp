/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        if(!headA || !headB) return nullptr;

        ListNode *d1 = headA, *d2 = headB;

        while(d1 != d2){

            //if one of the pointer reach null, point it to respective head again
            d1 = d1 ? d1->next : headA;
            d2 = d2 ? d2->next : headB;
        }

        return d1;
    }
};