class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int count = 0;
        int max_count = 0;

        int n = nums.size();

        int i = 0;

        while(i < n){

            if(nums[i] == 1){

                count++;
                max_count = max(max_count, count);
                i++;
            } else{

                count = 0;
                i++;
            }
        }

        return max_count;
    }
};