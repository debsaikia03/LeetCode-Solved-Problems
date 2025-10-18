class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end());

        int count = 0, prev = INT_MIN;

        for(int i = 0; i < nums.size(); i++){

            int minVal = nums[i] - k;

            if(prev < minVal){

                //nums[i] = nums[i] - k
                prev = minVal;
                count++;
            }else if(prev < nums[i] + k){
                
                //nums[i] = prev + 1;
                prev = prev+1;
                count++;
            }
        }

        return count;
    }
};