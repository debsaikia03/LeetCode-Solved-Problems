class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int n = nums.size();

        int prefixSum = 1, suffixSum = 1, maxSum = INT_MIN;

        for(int i = 0; i < n; i++){


            if(prefixSum == 0) prefixSum = 1;
            if(suffixSum == 0) suffixSum = 1;

            prefixSum = prefixSum * nums[i];
            suffixSum = suffixSum * nums[n - i - 1];

            maxSum = max(maxSum, max(prefixSum, suffixSum));
        }

        return maxSum;
    }
};