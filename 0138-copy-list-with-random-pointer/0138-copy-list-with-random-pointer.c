/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */

struct Node* copyRandomList(struct Node* head) {

    if (!head){

        return NULL;
    }
	
    struct Node* temp = head;

    while(temp != NULL){

        struct Node* copyNode = (struct Node*)malloc(sizeof(struct Node));

        copyNode->val = temp->val;
        copyNode->next = temp->next;
        copyNode->random = NULL;

        temp->next = copyNode;
        temp = temp->next->next;
    }

    temp = head;

    while(temp != NULL){

        struct Node* copyNode = temp->next;

        if(temp->random != NULL) copyNode->random = temp->random->next;

        temp = temp->next->next;
    }

    struct Node* dummyNode = (struct Node*)malloc(sizeof(struct Node));

    struct Node* res = dummyNode;
    temp = head;
    
    while(temp != NULL){

        res->next = temp->next;
        temp->next = temp->next->next;

        res = res->next;
        temp = temp->next;
    }

    return dummyNode->next;
}