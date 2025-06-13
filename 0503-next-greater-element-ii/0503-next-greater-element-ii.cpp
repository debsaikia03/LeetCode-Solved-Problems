class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

        int n = nums.size();
        stack<int> stk;
        vector<int> ans(n);


        for(int i = 2*n-1; i >= 0; i--){

            int idx = i % n;

            while(!stk.empty() && nums[stk.top()] <= nums[idx]){
                stk.pop();
            }

            if(stk.empty()) ans[idx] = -1;

            else ans[idx] = nums[stk.top()];

            stk.push(idx);
        }

        return ans;
    }
};