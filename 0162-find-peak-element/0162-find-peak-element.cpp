class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        
        int low = 0, high = n - 1;
        
        while(low < high) {
    
            int mid = low + (high - low) / 2;
            
            if(nums[mid] > nums[mid + 1]) {
                // You are in the descending part, move left
                high = mid;
            } else {
                // You are in the ascending part, move right
                low = mid+1;
            }
        }
        
        // low == high is the peak element index
        return low;
    }
};
