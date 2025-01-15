/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseLL(struct ListNode * head){

    struct ListNode* temp = head;
    struct ListNode* prev = NULL;

    while(temp != NULL){

        struct ListNode* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }

    return prev;
}

struct ListNode* getKthNode(struct ListNode* temp, int k){
    
    k--;

    while(temp != NULL && k > 0){

        k--;
        temp = temp->next;
    }

    return temp;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    
    struct ListNode* temp = head;
    struct ListNode* prevNode = NULL;

    while(temp != NULL){

        struct ListNode* kthNode = getKthNode(temp, k);

        if(kthNode == NULL){
            
            if(prevNode) prevNode->next = temp;
            break;
        }

        struct ListNode* nextNode = kthNode->next;
        kthNode->next = NULL;

        reverseLL(temp);

        if(temp == head){

            head = kthNode;
        } 

        else{

            prevNode->next = kthNode;
        }

        prevNode = temp;
        temp = nextNode;
    }

    return head;
}