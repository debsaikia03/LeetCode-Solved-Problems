class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        
        int i = 0;
        while(i < nums.size()){

            if(nums[i] % 2 == 0){

                nums[i] = 0;
            }else{

                nums[i] = 1;
            }

            i++;
        }

        sort(nums.begin(), nums.end());

        return nums;
    }
};