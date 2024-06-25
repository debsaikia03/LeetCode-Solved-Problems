/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void reorderList(struct ListNode* head) {

    if (!head || !head->next) return;

    struct ListNode *slow = head, *fast = head;
    struct ListNode *first, *second, *curr, *next, *prev;

    // Find the middle of the list
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }

    // Reverse the second half of the list
    second = slow->next;
    slow->next = NULL;
    curr = second;
    prev = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    second = prev;

    // Merge the two halves
    first = head;
    struct ListNode *temp1, *temp2;

    while (second != NULL) {
        temp1 = first->next;
        temp2 = second->next;
        first->next = second;
        second->next = temp1;
        first = temp1;
        second = temp2;
    }
}
