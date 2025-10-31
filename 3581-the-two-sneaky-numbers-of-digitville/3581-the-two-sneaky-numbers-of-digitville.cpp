class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        
        unordered_map<int, int> freq;

        vector<int> res;

        for(int num : nums){

            freq[num]++;

            if(freq[num] == 2){

                res.push_back(num);
            }

            if(res.size() == 2) return res;
        }

        return {};
    }
};