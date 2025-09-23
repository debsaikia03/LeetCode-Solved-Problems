class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        
        unordered_map<int, int> mpp;

        for(int num : nums){

            mpp[num]++;
        }

        int mx = 0;

        for(auto& p : mpp){

            mx = max(mx, p.second);
        }

        int maxF = 0;

        for(auto& p : mpp){

            if(p.second == mx){

                maxF += p.second;
            }
        }
        
        return maxF;
    }
};