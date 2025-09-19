class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        /*unordered_map<int, int> mpp;

        for(int i = 0; i < nums.size(); i++){

            mpp[nums[i]]++;
        }

        for(auto it: mpp){

            if(it.second > (nums.size()/2)){

                return it.first;
            }
        }

        return -1;*/

        int count = 0, candidate = 0;

        for(int num : nums){

            if(num == candidate){

                count++;
            } else if(count == 0){

                candidate = num;
            } else{

                count--;
            }
        }

        return candidate;
    }
};