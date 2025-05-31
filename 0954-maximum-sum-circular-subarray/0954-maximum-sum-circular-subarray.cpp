class Solution {
public:

    int kadane(vector<int> nums){

        int sum = 0, maxN = INT_MIN;

        for(int i = 0; i < nums.size(); i++){

            sum += nums[i];
            maxN = max(sum, maxN);

            if(sum < 0) sum = 0;
        }

        return maxN;
    }

    int minKadane(vector<int> nums){

        int sum = 0, minN = INT_MAX;

        for(int i = 0; i < nums.size(); i++){

            sum += nums[i];
            minN = min(sum, minN);

            if(sum > 0) sum = 0;
        }

        return minN;
    }

    int maxSubarraySumCircular(vector<int>& nums) {


        int sum = 0;

        for(int i = 0; i < nums.size(); i++){

            sum += nums[i];
        }

        int maxN = kadane(nums), minN = minKadane(nums);

        if(maxN < 0) return maxN;

        return max(maxN, sum - minN);
    }
};