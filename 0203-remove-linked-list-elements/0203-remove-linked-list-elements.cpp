/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
ListNode* removeElements(ListNode* head, int val) {

    // Step 1: Remove all starting nodes that have the value 'val'
    // This ensures 'head' points to the first node we want to keep
    while (head && head->val == val) {
        head = head->next; // Move forward until head is valid or list becomes empty
    }

    // Keep a pointer to the new head for the return value
    ListNode* r = head;

    // Step 2: Traverse the rest of the list
    while (head && head->next) {
        
        if (head->next->val == val) {
            // Found a node to remove: skip it by linking to the node after it
            head->next = head->next->next;

            // ⚠️ IMPORTANT:
            // We do NOT move 'head' forward here, because we need to check the new head->next again.
            // This is important when there are consecutive nodes with the same value.
        } 
        else {
            // No deletion needed → safe to move to the next node
            head = head->next;
        }
    }

    return r; // Return the updated head
}

};