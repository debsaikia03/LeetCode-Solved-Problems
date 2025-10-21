class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        
        int mx = *max_element(nums.begin(), nums.end()) + k;

        vector<int> freq(mx + 1, 0);

        for(int &num : nums){

            freq[num]++;
        }
        
        //cummulative freq sum
        for(int i = 1; i <= mx; i++){

            freq[i] += freq[i-1];
        }


        int result = 0;
        for(int target = 0; target <= mx; target++){

            if(freq[target] == 0)
                continue;

            int leftNum = max(0, target - k);
            int rightNum = min(mx, target + k);

            int totalCount = freq[rightNum] - (leftNum > 0 ? freq[leftNum - 1] : 0);
            int targetCount = freq[target] - (target > 0 ? freq[target - 1] : 0);
            int needConversion =  totalCount - targetCount;

            int maxPossibleFreq = targetCount + min(needConversion, numOperations);

            result = max(result, maxPossibleFreq);
        }

        return result;
    }
};