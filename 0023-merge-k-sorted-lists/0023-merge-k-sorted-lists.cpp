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
    // Function to merge k sorted linked lists
ListNode* mergeKLists(vector<ListNode*>& lists) {
    vector<int> res; // Vector to store all node values

    // Step 1: Extract all elements from each list
    for (auto list : lists) {
        while (list) {
            res.push_back(list->val);
            list = list->next;
        }
    }

    // Step 2: Sort all values
    sort(res.begin(), res.end());

    // Step 3: Build the merged list using dummy pointer
    // Create a dummy node (placeholder) with value 0
    ListNode* dummy = new ListNode(0);

    // Tail will always point to the last node of the new list
    ListNode* tail = dummy;

    // Step 4: Insert sorted values into the new linked list
    for (int val : res) {
        // Create a new node and attach it to tail->next
        tail->next = new ListNode(val);

        // Move tail to the newly created node
        tail = tail->next;
    }

    // The real head is dummy->next (skip dummy placeholder)
    return dummy->next;
}
};