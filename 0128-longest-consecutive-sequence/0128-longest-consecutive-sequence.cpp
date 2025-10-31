class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if(nums.size() == 0) return 0;
        
        sort(nums.begin(), nums.end());

        int mxLen = 1;
        
        int len = 1;

        for(int i = 1; i < nums.size(); i++){

            if(nums[i] == nums[i-1]) continue;

            if(nums[i] - nums[i-1] == 1) len++; 

            else{      
               mxLen = max(mxLen, len);
               len = 1;
            }
        }

        return max(mxLen, len);
    }
};