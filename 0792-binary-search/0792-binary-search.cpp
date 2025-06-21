class Solution {
public:
    
    int binarySearch(vector<int>& nums, int l, int r, int target){

        if(l > r) return -1;

        int mid = l + (r-l)/2;

        if(nums[mid] < target){
            return binarySearch(nums, mid+1, r, target);
        }
        else if(nums[mid] > target){
            return binarySearch(nums, l, mid-1, target);
        }
        else{
            return mid;
        }
    }


    int search(vector<int>& nums, int target) {
        
        int l = 0;
        int r = nums.size()-1;

        return binarySearch(nums,l,r,target);
    }
};