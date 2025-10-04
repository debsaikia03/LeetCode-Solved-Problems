class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int i = 0, j = height.size() - 1;

        int mxArea = 0;

        while(i < j){

            int area = 0;
            if(height[i] < height[j]){
 
                area = height[i] * (j - i);
                i++;
                mxArea = max(mxArea, area);
            } else{

                area = height[j] * (j - i);
                j--;
                mxArea = max(mxArea, area); 
            }
        }

        return mxArea;
    }
};