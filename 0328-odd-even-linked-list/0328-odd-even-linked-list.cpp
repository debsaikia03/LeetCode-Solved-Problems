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
        
        //if the list has 0 or 1 node, no rearrangement is needed
        if(!head || !head->next) return head;

        //'odd' will track the current odd node
        //'even' will track the current even node
        ListNode *odd = head, *even = head->next;
        ListNode* evenHead = even;

        //save the starting point of even list
        //this will be attached after odd list ends
        while(even && even->next){

           //link current odd node to the next odd node
           odd->next = odd->next->next;

           //link current even node to the next even node
           even->next = even->next->next;

           //move odd and even pointers forward
           odd = odd->next;
           even = even->next;
        }

        //attach the even list after the last odd node
        odd->next = evenHead;

        //head now represents rearranged list
        return head;
    }
};