class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        
        int size = nums1.length + nums2.length;
        int count = 0;
        int i = 0, j = 0;
        
        if (size % 2 == 0) {
            // Even case
            int flag[] = new int[2];
            // Fix 1: Typo (Integer) and initialization logic
            flag[0] = 0; 
            flag[1] = 0; 

            while (i < nums1.length && j < nums2.length) {
                flag[0] = flag[1]; // Always store the previous element
                if (nums1[i] < nums2[j]) {
                    flag[1] = nums1[i];
                    i++;
                } else {
                    flag[1] = nums2[j];
                    j++;
                }
                count++;

                // Fix 4: Corrected off-by-one check
                // Fix 3: Corrected integer division
                if (count == size / 2 + 1) {
                    return (flag[0] + flag[1]) / 2.0; 
                }
            }

            // Handle remaining elements in nums1
            while (i < nums1.length) {
                flag[0] = flag[1];
                flag[1] = nums1[i];
                i++;
                count++;
                
                if (count == size / 2 + 1) {
                    return (flag[0] + flag[1]) / 2.0;
                }
            }

            // Handle remaining elements in nums2
            while (j < nums2.length) {
                flag[0] = flag[1];
                // Fix 2: Typo (j instead of i)
                flag[1] = nums2[j]; 
                j++;
                count++;

                if (count == size / 2 + 1) {
                    return (flag[0] + flag[1]) / 2.0;
                }
            }

        } else {
            // Odd case (Your logic here was already correct!)
            int flag = -1;

            while (i < nums1.length && j < nums2.length) {
                if (nums1[i] < nums2[j]) {
                    flag = nums1[i];
                    i++;
                } else {
                    flag = nums2[j];
                    j++;
                }
                count++;

                if (count == size / 2 + 1) {
                    return (double)flag;
                }
            }
            
            while (i < nums1.length) {
                flag = nums1[i];
                i++;
                count++;

                if (count == size / 2 + 1) {
                    return (double)flag;
                }
            }
            
            while (j < nums2.length) {
                flag = nums2[j];
                j++;
                count++;

                if (count == size / 2 + 1) {
                    return (double)flag;
                }
            }
        }
        
        // This line should ideally not be reached if inputs are valid
        return 0.0; 
    }
}