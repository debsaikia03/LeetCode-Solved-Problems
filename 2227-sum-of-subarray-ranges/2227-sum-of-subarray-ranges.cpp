class Solution {
public:
    // Function to calculate the sum of ranges of all subarrays
    long long subArrayRanges(vector<int>& nums) {
        long long maxSum = calculateSum(nums); // Sum of max elements of all subarrays
      
        // Negate all the elements to use the same function for minimum
        for (int i = 0; i < nums.size(); ++i) {
            nums[i] *= -1;
        }
      
        long long minSum = calculateSum(nums); // Sum of min elements of all subarrays
        return maxSum + minSum; // Sum of ranges (max-min) of all subarrays
    }

    // Helper function to calculate the sum of either max or min elements of all subarrays
    long long calculateSum(vector<int>& nums) {
        stack<int> st; // Stack to maintain indices
        int n = nums.size();
        vector<int> left(n, -1); // Indices of previous smaller or equal elements
        vector<int> right(n, n); // Indices of next smaller elements
        long long sum = 0; // Resulting sum

        // Fill left array with previous smaller or equal indices
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && nums[st.top()] <= nums[i]) st.pop();
            if (!st.empty()) left[i] = st.top();
            st.push(i);
        }
      
        // Clear stack to reuse it for the right array
        st = stack<int>();

        // Fill right array with next smaller indices
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && nums[st.top()] < nums[i]) st.pop();
            if (!st.empty()) right[i] = st.top();
            st.push(i);
        }

        // Calculate the sum based on the left and right arrays
        for (int i = 0; i < n; ++i) {
            sum += (long long) (i - left[i]) * (right[i] - i) * nums[i];
        }

        return sum; // Return the total sum for the array
    }
};