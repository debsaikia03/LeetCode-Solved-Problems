class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        //optimal solution -> O(logn) in java

        if(nums.empty()){

            return {-1,-1};
        }

        vector<int> res(2,-1);

        int i = 0;
        while(i < nums.size()){

            if(target != nums[i]){

               i++;
            }else{

                break;
            }
        }

        if(i == nums.size()){

            return {-1,-1};
        }

        int j = i;

        res[0] = i;

        while(j < nums.size() && nums[j] == target){

            j++;
        }

        res[1] = j-1;

        return res;
    }
};