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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        if(!head) return nullptr;

        int len = 0;

        ListNode* r = head;

        while(r != nullptr){

            len++;
            r = r->next;
        }

        if (n == len) return head->next; 

        int prevDeleteNode = len - n - 1;//find the node before the delete node

        r = head;

        while(prevDeleteNode){

           r = r->next;
           prevDeleteNode--;
        } 

        r->next = r->next->next;

        return head;
    }
};