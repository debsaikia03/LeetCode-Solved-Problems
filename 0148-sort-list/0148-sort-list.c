/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* merge(struct ListNode* left, struct ListNode* right) {
    if (!left) return right;
    if (!right) return left;
    
    if (left->val <= right->val) {
        left->next = merge(left->next, right);
        return left;
    } else {
        right->next = merge(left, right->next);
        return right;
    }
}

struct ListNode* sortList(struct ListNode* head) {
    if (!head || !head->next) return head;

    struct ListNode *slow = head, *fast = head;
    struct ListNode *prev = NULL;

    // Use the fast and slow pointers to find the middle of the list
    while (fast && fast->next) {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }

    // Split the list into two halves
    prev->next = NULL;

    // Recursively sort both halves
    struct ListNode* left = sortList(head);
    struct ListNode* right = sortList(slow);

    // Merge the sorted halves
    return merge(left, right);
}
