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
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if(!head || left == right) return head;

        //create a dummy node connecting to the head node
        //handles edge case if the left = 1
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* leftPrev = dummy;
        ListNode* currNode = head;

        //iterate to reach the left & previous left node of the linked list
        for(int i = 0; i < left - 1; i++){

            leftPrev = leftPrev->next; //will reach left - 1 node
            currNode = currNode->next; //will reach left node
        }

        //make a marker to the node where we start reversing
        ListNode* subListHead = currNode;

        ListNode* prevNode = nullptr;

        for(int i = 0; i < right - left + 1; i++){

            ListNode* nextNode = currNode->next;
            currNode->next = prevNode;
            prevNode = currNode;
            currNode = nextNode;
        }

        //joining the pieces
        leftPrev->next = prevNode;
        subListHead->next = currNode;

        return dummy->next;
    }
};