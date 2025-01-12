/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {

    if(!headA || !headB) return NULL;
    
    struct ListNode* d1 = headA;
    struct ListNode* d2 = headB;

    while(d1 != d2){

        d1 = d1 ? d1->next : headB;
        d2 = d2 ? d2->next : headA;
    }

    return d1;
}