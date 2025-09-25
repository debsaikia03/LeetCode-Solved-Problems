class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> res;

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int i = 0, j = 0;
       
        while(i < nums1.size() && j < nums2.size()){

          if(nums1[i] == nums2[j]){

            res.push_back(nums1[i]);

            // skip duplicates in nums1
            int val = nums1[i];
            while (i < nums1.size() && nums1[i] == val) i++;

            // skip duplicates in nums2
            while (j < nums2.size() && nums2[j] == val) j++;
          } else if(nums1[i] < nums2[j]){

            i++;
          }else{

            j++;
          }
        }

        return res;
    }
};