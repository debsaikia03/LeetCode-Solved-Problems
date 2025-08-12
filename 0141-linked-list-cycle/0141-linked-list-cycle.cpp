/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // If the list is empty or has only one node, it can't have a cycle
        if (!head || !head->next) return false;

        // slow moves 1 step at a time, fast moves 2 steps
        ListNode* slow = head;
        ListNode* fast = head;

        // Continue while fast can take two steps ahead
        while (fast && fast->next) {
            slow = slow->next;           // move slow pointer by 1 step
            fast = fast->next->next;     // move fast pointer by 2 steps

            // If slow and fast meet, it means there is a cycle
            if (slow == fast) return true;
        }

        // If fast reaches the end (nullptr), there is no cycle
        return false;
    }
};
