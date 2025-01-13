/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* rotateRight(struct ListNode* head, int k) {

    if(!head || !head->next || k == 0){

        return head;
    }
  
    int len = 1;

    struct ListNode* tail = head;

    while(tail->next != NULL){

        tail = tail->next;
        len++;
    }

    k = k % len;

    if(k == 0){

        return head;
    }

    tail->next = head;

    struct ListNode* temp = head;

    for(int i = 0; i < len - k - 1; i++){

        temp = temp->next;
    }
 
    head = temp->next;
    temp->next = NULL;

    return head;
}