class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        // If one of the lists is empty, return the other
        if (!list1) return list2;
        if (!list2) return list1;

        ListNode* newHead = nullptr; // Head of the merged list
        ListNode* newTail = nullptr; // Tail pointer for building merged list

        // Step 1: Initialize the head with the smaller of the two first nodes
        if (list1->val <= list2->val) {
            newHead = newTail = list1; // Both head and tail point to first node
            list1 = list1->next;       // Move list1 forward
        } else {
            newHead = newTail = list2;
            list2 = list2->next;       // Move list2 forward
        }

        // Step 2: Traverse both lists until one becomes empty
        while (list1 && list2) {
            if (list1->val <= list2->val) {
                // Attach list1's current node to the merged list
                newTail->next = list1;
                newTail = list1;       // Move the tail forward
                list1 = list1->next;   // Advance list1
            } else {
                // Attach list2's current node to the merged list
                newTail->next = list2;
                newTail = list2;       // Move the tail forward
                list2 = list2->next;   // Advance list2
            }
        }

        // Step 3: Attach any remaining nodes from list1
        while (list1) {
            newTail->next = list1;     // Link remaining nodes
            newTail = list1;           // Move the tail
            list1 = list1->next;       // Advance list1
        }

        // Step 4: Attach any remaining nodes from list2
        while (list2) {
            newTail->next = list2;     // Link remaining nodes
            newTail = list2;           // Move the tail
            list2 = list2->next;       // Advance list2
        }

        // Return the head of the merged list
        return newHead;
    }
};
