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
    ListNode* oddEvenList(ListNode* head) {

        // If the list has 0 or 1 node, no rearrangement is needed
        if(!head || !head->next) return head;

        // 'odd' will track the current odd node
        // 'even' will track the current even node
        ListNode *odd = head, *even = head->next;

        // Save the starting point of even list
        // This will be attached after odd list ends
        ListNode* evenHead = even;

        // Traverse until even pointer or its next becomes NULL
        // This ensures we do not go out of bounds
        while(even && even->next){

            // Link current odd node to the next odd node
            odd->next = odd->next->next;

            // Link current even node to the next even node
            even->next = even->next->next;

            // Move odd and even pointers forward
            odd = odd->next;
            even = even->next;
        }

        // Attach the even list after the last odd node
        odd->next = evenHead;
        
        // Head now represents rearranged list
        return head;
    }
};
