class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {

        unordered_map<int, int> mpp;

        for(int &num : nums){

            int r = ((num % value) + value) % value;

            mpp[r]++;
        }

        int MEX = 0;

        while(mpp[(MEX % value)] > 0){

            mpp[(MEX % value)]--;
            MEX++;
        }

        return MEX;
    }
};