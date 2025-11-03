class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> ans(n,INT_MIN); //initialize answer array
        stack<int> stk; //stack to store indices

         //loop from 2*n - 1 to 0 to handle circular array
        for(int i = 2 * n - 1; i >= 0; i--){

            int idx = i % n; //get circular index

            //while stack not empty and current element >= top stack element
            while(!stk.empty() && nums[stk.top()] <= nums[idx]){

                stk.pop();  //pop smaller elements
            }
            
            //if stack not empty then top element is next greater
            if(stk.empty()) ans[idx] = -1;

            else ans[idx] = nums[stk.top()];

            //push current index to stack
            stk.push(idx);
        }

        return ans;
    }
};