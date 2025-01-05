int search(int* nums, int numsSize, int target) {
    int low = 0; 
    int high = numsSize - 1;

    while (low <= high) {
        int mid = (low + high) / 2; // Calculate mid-point

        if (nums[mid] == target) { // Target found
            return mid;
        }

        // Check if the left half is sorted
        if (nums[low] <= nums[mid]) {
            // If the target lies within the sorted left half
            if (nums[low] <= target && target < nums[mid]) {
                high = mid - 1; // Search left half
            } else {
                low = mid + 1; // Search right half
            }
        }
        // Otherwise, the right half must be sorted
        else {
            // If the target lies within the sorted right half
            if (nums[mid] < target && target <= nums[high]) {
                low = mid + 1; // Search right half
            } else {
                high = mid - 1; // Search left half
            }
        }
    }

    return -1; // Target not found
}
