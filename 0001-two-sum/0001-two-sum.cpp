class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int, int> mpp;

        for(int i = 0; i < nums.size(); i++){

            int n = nums[i];

            int more = target - nums[i];

            if(mpp.find(more) != mpp.end()){

                return {mpp[more], i};
            }

            mpp[n] = i;
        }

        return {};
    }
};