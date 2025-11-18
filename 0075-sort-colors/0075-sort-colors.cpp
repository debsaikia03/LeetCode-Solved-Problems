class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int zeros = 0, ones = 0, twos = 0;

        for(int num : nums){

            if(num == 0) zeros++;
            else if(num == 1) ones++;
            else twos++;
        }

        int i = 0;
        while(i < nums.size()){

            if(zeros){

               nums[i] = 0;
               zeros--;
            }else if(ones){

                nums[i] = 1;
                ones--;
            }else{

                nums[i] = 2;
                twos--;
            }
            i++;
        }
    }
};