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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {

        unordered_set<int> st(nums.begin(), nums.end());
        
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* prev = dummy;
        ListNode* r = head;

        while(r != nullptr){

            if(st.count(r->val)){//lookup: O(1)

               prev->next = r->next;
               r = r->next;
            }else{

                prev = r;
                r = r->next;
            }
        }

        return dummy->next;
    }
};