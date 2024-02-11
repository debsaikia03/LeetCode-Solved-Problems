class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {

        int i=0, j=0;
        
        i=m;

        
        while(i<m+n){
            nums1[i]=nums2[j];
            i++;
            j++;
        }
    
      if(m!=0 && n!=0){
        int temp;
        for(i=0; i<m+n; i++)
        {
          temp = nums1[i];
          j = i-1;

          while(j>=0 && nums1[j]>temp)
          {
              nums1[j+1] = nums1[j];
              j--;
          }
          nums1[j+1] = temp;
        }
      }
    }
}