class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {

        int n = nums.size();
        int count = 0, maxCount = 0;

        int i = 0;

        while(i < n){

            if(nums[i] == 1){

                count++;
                i++;
            }else{

                maxCount = max(maxCount, count);
                count = 0;
                i++;
            }
        }

        maxCount = max(maxCount, count);
        
        return maxCount;
    }
};