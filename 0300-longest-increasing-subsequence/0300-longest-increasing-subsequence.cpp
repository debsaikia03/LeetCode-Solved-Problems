class Solution {
public:
    // Recursive function with memoization
    // idx = current index, prev_idx = index of last taken element (-1 if none)
    int f(int idx, int prev_idx, vector<int>& nums, int n, vector<vector<int>>& dp) {
        if (idx == n) return 0; // base case: reached end

        if (dp[idx][prev_idx + 1] != -1) 
            return dp[idx][prev_idx + 1]; // return memoized result

        // Option 1: skip current element
        int len = f(idx + 1, prev_idx, nums, n, dp);

        // Option 2: take current element (if it forms increasing subsequence)
        if (prev_idx == -1 || nums[idx] > nums[prev_idx]) {
            len = max(len, 1 + f(idx + 1, idx, nums, n, dp));
        }

        return dp[idx][prev_idx + 1] = len; // store result
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // dp[i][j] = LIS length starting at index i with prev_idx = j-1
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return f(0, -1, nums, n, dp);
    }
};
