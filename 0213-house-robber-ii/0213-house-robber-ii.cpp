class Solution {
public:

    int robDP(vector<int>& nums, int start, int end){

        int n = end - start + 1;

        if(n == 1) return nums[start];
        
        if(n == 2) return max(nums[start], nums[start+1]);

        int dp[n];

        dp[0] = nums[start];
        dp[1] = max(nums[start], nums[start+1]);

        for(int i = 2; i < n; i++){

            dp[i] = max(dp[i-1], dp[i-2] + nums[start + i]);
        }

        return dp[n-1];
    }

    int rob(vector<int>& nums) {

        int n = nums.size();
        
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);

        int case1 = robDP(nums, 0, n-2); //from house 0 to n-2
        int case2 = robDP(nums, 1, n-1); //from house 1 to n-1

        return max(case1, case2);
    }
};