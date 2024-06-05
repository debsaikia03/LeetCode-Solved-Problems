class Solution {
    public int search(int[] nums, int target) {
        
        /*for(int i = 0; i<nums.length; i++){
            if(target == nums[i]){
                return i;
            }
        }

        return -1;
        */

        int l = 0;
        int r = nums.length-1;
        int mid;

        while(l<=r){
            mid = l+(r-l)/2;

            if(nums[mid] > target){
                r=mid-1;
            }

            else if(nums[mid] < target){
                l=mid+1;
            }

            else{
                return mid;
            }

        }

        return -1;
    }
}