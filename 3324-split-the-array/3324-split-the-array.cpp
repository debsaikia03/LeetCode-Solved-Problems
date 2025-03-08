class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {


        unordered_map<int, int> freq;

        for(int val : nums){

            freq[val]++;

            if(freq[val] > 2){

               return false;
            }
        }

        return true;


    }
};