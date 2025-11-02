class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        //if one of the lists is empty, return the other
        if (!list1) return list2;
        if (!list2) return list1;

        ListNode* newHead = nullptr; //head of the merged list
        ListNode* newTail = nullptr; //tail pointer for building merged list

        //initialize the head with the smaller of the two first nodes
        if (list1->val <= list2->val) {
            newHead = newTail = list1; //both head and tail point to first node
            list1 = list1->next;       //move list1 forward
        } else {
            newHead = newTail = list2;
            list2 = list2->next;       //move list2 forward
        }

        //traverse both lists until one becomes empty
        while (list1 && list2) {
            if (list1->val <= list2->val) {
                //attach list1ee's current node to the merged list
                newTail->next = list1;
                newTail = list1;       //move the tail forward
                list1 = list1->next;   //advance list1
            } else {
                //attach list2's current node to the merged list
                newTail->next = list2;
                newTail = list2;       //move the tail forward
                list2 = list2->next;   //advance list2
            }
        }

        //attach any remaining nodes from list1
        while (list1) {
            newTail->next = list1;     //link remaining nodes
            newTail = list1;           //move the tail
            list1 = list1->next;       //advance list1
        }

        //attach any remaining nodes from list2
        while (list2) {
            newTail->next = list2;     //link remaining nodes
            newTail = list2;           //move the tail
            list2 = list2->next;       //advance list2
        }

        //return the head of the merged list
        return newHead;
    }
};
