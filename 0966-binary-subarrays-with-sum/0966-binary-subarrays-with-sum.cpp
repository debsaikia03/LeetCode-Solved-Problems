class Solution {
public:

    int compute(vector<int>& nums, int goal){

        int l = 0, r = 0, sum = 0, count = 0;

        while(r < nums.size()){
            sum+= nums[r];

            while(sum > goal && l <= r){
                sum = sum - nums[l];
                l++;
            }

            count += (r-l+1);
            r++;
        }

        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {

        int count1 = compute(nums, goal);
        int count2 = compute(nums, goal-1);

        return count1 - count2;
    }
};