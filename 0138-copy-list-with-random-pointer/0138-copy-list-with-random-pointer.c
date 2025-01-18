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
        temp = copyNode->next;
    }

    temp = head;

    while(temp != NULL){

        struct Node* copyNode = temp->next;

        if(temp->random != NULL) copyNode->random = temp->random->next;

        temp = copyNode->next;
    }

    struct Node* dummyNode = (struct Node*)malloc(sizeof(struct Node));

    struct Node* res = dummyNode;
    temp = head;
    
    while(temp != NULL){

        struct Node* copyNode = temp->next;
        temp->next = copyNode->next;

        res->next = copyNode;

        res = res->next;
        temp = temp->next;
    }

    return dummyNode->next;
}