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
    ListNode* deleteDuplicates(ListNode* head) {

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        
        ListNode* slow = dummy, *fast = head;

        while(fast){
            
            bool duplicate = false;
 
            while(fast->next && fast->val == fast->next->val){

                fast = fast->next;
                duplicate = true;
            }

            if(duplicate == true){

                slow->next = fast->next;
            }else{

                slow = slow->next;
            }

            fast = fast->next;
        }

        return dummy->next;
    }
};