class Solution {

    public int[] searchRange(int[] nums, int target) {
        

        int left = findLeftBound(nums, target);
        int right = findRightBound(nums, target);

        return new int[]{left, right};
    }

    private int findLeftBound(int[] nums, int target){

        int idx = -1, low = 0, high = nums.length - 1;

        while(low <= high){

            int mid = low + (high - low) / 2;

            if(nums[mid] == target){

                idx = mid;
                high = mid - 1;
            } else if(nums[mid] < target){

                low = mid + 1;
            } else{

                high = mid - 1;
            }
        }

        return idx;
    }

    private int findRightBound(int[] nums, int target){

        int idx = -1, low = 0, high = nums.length - 1;

        while(low <= high){

            int mid = low + (high - low) / 2;

            if(nums[mid] == target){

                idx = mid;
                low = mid + 1;
            } else if(nums[mid] < target){

                low = mid + 1;
            } else{

                high = mid - 1;
            }
        }

        return idx;
    }

}