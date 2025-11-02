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

        ListNode* prev = nullptr;
        ListNode* temp = head;

        while(temp != nullptr){

            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }

        return prev;
    }

    bool isPalindrome(ListNode* head) {
        
        if(!head || !head->next) return true;

        ListNode* fast = head;
        ListNode* slow = head;

        while(fast && fast->next){

            slow = slow->next;
            fast = fast->next->next;
        }

        slow = reverseList(slow);

        while(slow){

            if(slow->val != head->val){

                return false;
            }

            slow = slow->next;
            head = head->next;
        }

        return true;
    }
};