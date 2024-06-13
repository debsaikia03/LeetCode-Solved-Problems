class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int l = 0;
        int r = height.size()-1;
        int max_area = 0;

        while(l < r){
            int height1 = std::min(height[l],height[r]);
            int width = r-l;
            int area = height1 * width;

            max_area = std::max(area,max_area);

            if(height[l] < height[r]){
                l++;
            }
            else if(height[r] < height[l]){
                r--;
            }
            else{
                l++;
                r--;
            }
        }

        return max_area;
    }
};