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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if(!list1) return list2;
        if(!list2) return list1;

        ListNode* newHead = nullptr;
        ListNode* newTail = nullptr;

        if(list1->val < list2->val){

            newHead = newTail = list1;
            list1 = list1->next;
        }else{

            newHead = newTail = list2;
            list2 = list2->next;
        }

        while(list1 && list2){

            if(list1->val < list2->val){

               newTail->next = list1;
               newTail = list1;
               list1 = list1->next;
            }else{

                newTail->next = list2;
                newTail = list2;
                list2 = list2->next;
            }
        }
        
        while(list1){

            newTail->next = list1;
            newTail = list1;
            list1 = list1->next;
        }

        while(list2){

            newTail->next = list2;
            newTail = list2;
            list2 = list2->next;
        }

        return newHead;
    }
};