class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_map<int,int> mpp;
        stack<int> stk;

        for(int i = nums2.size()-1; i >= 0; i--){

            while(!stk.empty() && stk.top() <= nums2[i]){
                stk.pop();
            }

            if(stk.empty()) mpp[nums2[i]] = -1;

            else mpp[nums2[i]] = stk.top();

            stk.push(nums2[i]);
        }

        vector<int> ans;

        for(int i = 0; i < nums1.size(); i++){

            ans.push_back(mpp[nums1[i]]);
        } 

        return ans;
    }
};