class Solution {
public:
    int jump(vector<int>& nums) {
        
        int n = nums.size();

        int jumps = 0; //total no of min jumps

        int maxReach = 0; //furthest index we can reach
        int stepsEnd = 0; //end of current jump range

        for(int i = 0; i < n - 1; i++){

            maxReach = max(maxReach, i + nums[i]);

            if(i == stepsEnd){

              jumps++;
              stepsEnd = maxReach;
            }
        }

        return jumps;
    }
};