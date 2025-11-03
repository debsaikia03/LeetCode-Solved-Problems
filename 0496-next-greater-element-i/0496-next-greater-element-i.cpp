class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        int n1 = nums1.size(), n2 = nums2.size();

        //map to store the next greater element of each number in nums2
        unordered_map<int, int> mpp;

        //stack to maintain elements in decreasing order (monotonic stack)
        stack<int> stk;

        //traverse nums2 from right to left
        for (int i = n2 - 1; i >= 0; i--) {

            //pop elements from stack while they are smaller or equal
            //because they cannot be the next greater for the current element
            while (!stk.empty() && stk.top() <= nums2[i]) {
                stk.pop();
            }

            //if stack becomes empty, no greater element exists to the right
            if (stk.empty()) mpp[nums2[i]] = -1;

            //the top of the stack is the next greater element
            else mpp[nums2[i]] = stk.top();

            //push current element to stack for future comparisons
            stk.push(nums2[i]);
        }

        //result vector to store next greater elements for nums1
        vector<int> ans;

        //for each element in nums1, retrieve its next greater from the map
        for (int i = 0; i < nums1.size(); i++) {
            ans.push_back(mpp[nums1[i]]);
        }

        return ans;
    }
};
