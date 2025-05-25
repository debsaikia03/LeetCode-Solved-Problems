class Solution {
public:

    void swap(int &a, int &b){

        int temp = a;
        a = b;
        b = temp;
    }

    vector<int> sortArrayByParity(vector<int>& nums) {


        int i = 0, j= nums.size() - 1;

        while(i < j){

            while(nums[i] % 2 == 0 && i < j) i++;
            while(nums[j] % 2 != 0 && i < j) j--;

            if(i < j){

                swap(nums[i], nums[j]);
                i++;
                j--;
            }
        }

        return nums;
        
    }
};