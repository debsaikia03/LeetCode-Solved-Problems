class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        int n = nums.size();

        vector<int> result(n);

        int posIndex = 0, negIndex = 1;

        for(int i : nums){
        
            if(i > 0){
                result[posIndex] = i;
                posIndex += 2;
            } else {
                result[negIndex] = i;
                negIndex += 2;
            }
        }

        return result;
    }
};