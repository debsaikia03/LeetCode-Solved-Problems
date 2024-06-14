/*
Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
*/

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

        if(head == NULL || head->next == NULL){
            return nullptr;
        }
        
        ListNode *slow, *fast;

        slow = head;
        fast = head;

        while(fast != NULL && fast->next != NULL){

            fast = fast->next->next;
            slow = slow->next;

            if(fast == slow){

                fast = head;
                ListNode *pos = head;

                while(fast != slow){

                    fast = fast->next;
                    slow = slow->next;

                    pos = pos->next;
                }

                return pos;
            }
        }

        return nullptr;
    }       
};