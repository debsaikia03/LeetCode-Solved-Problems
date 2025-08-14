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

    // Function to reverse a linked list
    // Returns the new head of the reversed list
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;       // Current node pointer
        ListNode* prev = nullptr;    // Previous node pointer

        while (temp != nullptr) {
            ListNode* front = temp->next; // Save next node
            temp->next = prev;            // Reverse the link
            prev = temp;                  // Move 'prev' forward
            temp = front;                  // Move 'temp' forward
        }

        return prev; // 'prev' will be the new head after reversal
    }
    
    bool isPalindrome(ListNode* head) {
        // Edge case: 0 or 1 node is always a palindrome
        if (!head || !head->next) return true;

        // Step 1: Find the middle of the linked list using slow & fast pointers
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;           // Move slow by 1 step
            fast = fast->next->next;     // Move fast by 2 steps
        }
        // Now 'slow' points to the middle node

        // Step 2: Reverse the second half of the list starting from 'slow'
        slow = reverseList(slow);

        // Step 3: Compare the first half and the reversed second half
        ListNode* firstHalf = head;
        ListNode* secondHalf = slow; // This is now the head of the reversed part

        while (secondHalf) {
            if (firstHalf->val != secondHalf->val) 
                return false; // If mismatch found, it's not a palindrome

            // Move both pointers forward
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        // Step 4: If all matched, it's a palindrome
        return true;
    }
};
