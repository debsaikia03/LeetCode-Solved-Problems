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
    
    ListNode* reverseList(ListNode* head){

        ListNode* temp = head;
        ListNode* prev = nullptr;

        while(temp != nullptr){

            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }

        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        
        ListNode *slow = head, *fast = head;

        while(fast && fast->next){

            slow = slow->next;
            fast = fast->next->next;
        }

        slow = reverseList(slow);

        ListNode* firstHalf = head;
        ListNode* secondHalf = slow;

        while(secondHalf){

            if(firstHalf->val != secondHalf->val) return false;

            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        return true;
    }
};