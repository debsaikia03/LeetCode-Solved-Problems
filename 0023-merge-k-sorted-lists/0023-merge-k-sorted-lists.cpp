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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        vector<int> res;

        for(auto list : lists){

            while(list){

                res.push_back(list->val);
                list = list->next;
            }
        }

        sort(res.begin(), res.end());

        ListNode* dummy = new ListNode(0);

        ListNode* tail = dummy;

        for(int val : res){

            tail->next = new ListNode(val);
            tail = tail->next;
        }

        return dummy->next;
    }
};