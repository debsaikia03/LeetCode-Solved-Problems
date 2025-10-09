class Solution {
public:

    void swap(int& a, int& b){

        int temp = a;
        a = b;
        b = temp;
    }

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

        int j = nums.size() - 1;
        i = 0;

        while(i < j){

            if(nums[i] == 0){

                i++;
            }else if(nums[j] == 1){

                j--;
            }else{

                swap(nums[i], nums[j]);
                i++;
                j--;
            }
        }
        
        return nums;
    }
};