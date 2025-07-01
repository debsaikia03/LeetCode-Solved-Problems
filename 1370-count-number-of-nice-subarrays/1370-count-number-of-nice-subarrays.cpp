class Solution {
public:

    int compute(vector<int>& nums, int goal){

        int l = 0, r = 0, sum = 0, count = 0;

        while(r < nums.size()){
            sum+= (nums[r] % 2);

            while(sum > goal && l <= r){
                sum = sum - (nums[l] % 2);
                l++;
            }

            count += (r-l+1);
            r++;
        }

        return count;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        
        int count1 = compute(nums, k);
        int count2 = compute(nums, k-1);

        return count1 - count2;
    }
};