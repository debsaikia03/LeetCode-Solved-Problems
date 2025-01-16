/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {

    if(!head || !head->next) return NULL;
    
    struct ListNode* fast = head;
    struct ListNode* slow = head; 

    while(fast != NULL && fast->next != NULL){

        fast = fast->next->next;
        slow = slow->next;

        if(fast == slow) break;
    } 

    if(fast != slow) return NULL;

    struct ListNode* dummy = head;

    if(dummy == slow) return head;

    while(dummy != slow){

        dummy = dummy->next;
        slow = slow->next;
    }

    return slow;
}