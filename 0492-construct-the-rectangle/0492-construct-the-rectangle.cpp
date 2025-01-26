class Solution {
public:
    vector<int> constructRectangle(int area) {
        
        vector<int> ans;

        for(int i = 1; i <= sqrt(area); i++){

            if(area % i == 0){

                ans = {area/i, i};
            }
        }

        return ans;
        
    }
};