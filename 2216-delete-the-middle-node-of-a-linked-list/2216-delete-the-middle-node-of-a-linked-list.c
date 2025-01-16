/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteMiddle(struct ListNode* head) {
    
    if(!head || !head->next){

        return NULL;
    }

    struct ListNode* slow = head;
    struct ListNode* fast = head;
    struct ListNode* temp;

    while(fast != NULL && fast->next != NULL){

        fast = fast->next->next;
        temp = slow;
        slow = slow->next;
    }

    temp->next = slow->next;

    return head;
}