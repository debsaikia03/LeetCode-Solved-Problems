class Solution {
public:
    bool canJump(vector<int>& nums) {

        int n = nums.size();
        
        int maxFind = 0;

        for(int i = 0; i < n; i++){

            if(i > maxFind){

                return false;
            } 

            maxFind = max(maxFind, i + nums[i]);
        }
        
        return true;
    }
};