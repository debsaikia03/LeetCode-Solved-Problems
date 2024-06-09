/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {

    struct ListNode *dummy, *ptr;
    dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummy->val = 0;
    dummy->next = NULL;

    ptr = dummy;

    while(list1 != NULL && list2 != NULL){
        if(list1->val < list2->val){
            ptr->next = list1;
            list1 = list1->next;
        }

        else {
            ptr->next = list2;
            list2 = list2->next;
        }

        ptr = ptr->next;
    }

    if(list1 != NULL){
        ptr->next = list1;
    }

    else if(list2 != NULL){
        ptr->next = list2;
    }

    return dummy->next;
}