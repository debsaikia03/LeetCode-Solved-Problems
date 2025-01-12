/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    
    struct ListNode* t1 = l1;
    struct ListNode* t2 = l2;

    struct ListNode* dummyNode;
    dummyNode = (struct ListNode *)malloc(sizeof(struct ListNode));

    dummyNode->val = -1;
    dummyNode->next = NULL;

    struct ListNode* curr = dummyNode;
    int carry = 0;

    while(t1 != NULL || t2 != NULL){

        int sum = carry;

        if(t1) sum += t1->val;
        if(t2) sum += t2->val;

        struct ListNode* newNode;
        newNode = (struct ListNode *)malloc(sizeof(struct ListNode));        

        newNode->val = sum % 10;
        newNode->next = NULL;

        carry = sum / 10;

        curr->next = newNode;
        curr = curr->next;
        
        if(t1) t1 = t1->next;
        if(t2) t2 = t2->next;
    }

    if(carry){

        struct ListNode* newNode;
        newNode = (struct ListNode *)malloc(sizeof(struct ListNode)); 

        newNode->val = carry;
        newNode->next = NULL;

        curr->next = newNode;       
    }

    return dummyNode->next;
}