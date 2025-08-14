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
    int numComponents(ListNode* head, vector<int>& nums) {

        // Store all values from 'nums' in an unordered_set for O(1) lookup.
        // This allows us to quickly check if a node's value is part of nums.
        unordered_set<int> s(nums.begin(), nums.end());

        ListNode* r = head; // Pointer to traverse the linked list
        int count = 0;      // To store the number of connected components

        // Traverse the linked list
        while (r) {

            // Condition to identify the *end* of a component:
            // 1. Current node's value is in 'nums' (s.count(r->val) is true)
            // 2. The next node is either:
            //    a) NULL (end of list) OR
            //    b) Not in 'nums' (break in the component sequence)
            if (s.count(r->val) && (!r->next || !s.count(r->next->val))) {
                count++; // Found the end of a connected component
            }

            r = r->next; // Move to the next node
        }

        return count; // Return total number of connected components
    }
};
