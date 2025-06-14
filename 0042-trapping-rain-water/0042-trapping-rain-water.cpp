class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l_max, r_max, total;
        l_max = r_max = total = 0;
        int l = 0; 
        int r = n-1;

        while(l<r){
           if(height[l] <= height[r]){
               if(l_max > height[l]){
                  total += l_max - height[l];
               }
               else{
                l_max = height[l];
               }
               l++;
           }
           else{

            if(r_max >= height[r]){
                total += r_max - height[r];
            }
            else{
                r_max = height[r];
            }
            r--;
           }
        }
        
        return total;
    }
};