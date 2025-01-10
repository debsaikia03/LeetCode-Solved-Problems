class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        quickSortHelper(nums, 0, nums.size() - 1);
    }

private:
    void quickSortHelper(vector<int>& nums, int left, int right) {
        if (left >= right) return; // Base case: if the segment is too small, stop

        int pivotIndex = partition(nums, left, right); // Partition the array
        quickSortHelper(nums, left, pivotIndex - 1);   // Sort left part
        quickSortHelper(nums, pivotIndex + 1, right);  // Sort right part
    }

    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[right]; // Choose the last element as the pivot
        int i = left - 1;        // Pointer for the smaller element

        for (int j = left; j < right; ++j) {
            if (nums[j] <= pivot) { // If the current element is smaller than or equal to the pivot
                ++i;
                swap(nums[i], nums[j]); // Swap elements
            }
        }
        swap(nums[i + 1], nums[right]); // Place the pivot in its correct position
        return i + 1; // Return the index of the pivot
    }
};