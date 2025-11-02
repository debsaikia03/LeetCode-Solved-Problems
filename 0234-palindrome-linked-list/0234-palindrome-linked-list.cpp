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

    //function to reverse a linked list
    //returns the new head of the reversed list
    ListNode* reverseList(ListNode* head) {
        ListNode* temp = head;       //current node pointer
        ListNode* prev = nullptr;    //previous node pointer

        while (temp != nullptr) {
            ListNode* front = temp->next; //save next node
            temp->next = prev;            //reverse the link
            prev = temp;                  //move 'prev' forward
            temp = front;                  //move 'temp' forward
        }

        return prev; //'prev' will be the new head after reversal
    }
    
    bool isPalindrome(ListNode* head) {
        //edge case: 0 or 1 node is always a palindrome
        if (!head || !head->next) return true;

        //find the middle of the linked list using slow & fast pointers
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;           //move slow by 1 step
            fast = fast->next->next;     //move fast by 2 steps
        }
        //now 'slow' points to the middle node

        //reverse the second half of the list starting from 'slow'
        slow = reverseList(slow);

        //compare the first half and the reversed second half
        ListNode* firstHalf = head;
        ListNode* secondHalf = slow; //this is now the head of the reversed part

        while (secondHalf) {
            if (firstHalf->val != secondHalf->val) 
                return false; //if mismatch found, it's not a palindrome

            //move both pointers forward
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        //if all matched, it's a palindrome
        return true;
    }
};
