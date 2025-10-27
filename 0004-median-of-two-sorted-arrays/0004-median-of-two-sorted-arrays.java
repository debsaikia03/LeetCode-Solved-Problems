class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        
        int m = nums1.length;
        int n = nums2.length;
        int size = m + n;
        
        int i = 0, j = 0;
        
        // We use your 'flag' array idea from the 'even' case.
        // flag[0] will store the element at index (size/2) - 1
        // flag[1] will store the element at index (size/2)
        int[] flag = new int[2];

        int count = 0;
        
        // We iterate (size / 2) + 1 times to find both elements.
        while (count <= size / 2) {
            
            // 1. Store the *previous* element
            // This is the same as flag[0] = flag[1]
            flag[0] = flag[1]; 
            
            // 2. Find the *current* smallest element (the new flag[1])
            if (i < m && j < n) {
                if (nums1[i] < nums2[j]) {
                    flag[1] = nums1[i];
                    i++;
                } else {
                    flag[1] = nums2[j];
                    j++;
                }
            } else if (i < m) {
                // Only nums1 has elements left
                flag[1] = nums1[i];
                i++;
            } else {
                // Only nums2 has elements left
                flag[1] = nums2[j];
                j++;
            }

            count++;
        }
        
        // 3. Now that the loop is done, check if size was even or odd
        
        if (size % 2 == 0) {
            // Even case: return the average of the two elements we tracked
            return (double)(flag[0] + flag[1]) / 2.0;
        } else {
            // Odd case: return the single middle element (the last one found)
            return (double)flag[1];
        }
    }
}