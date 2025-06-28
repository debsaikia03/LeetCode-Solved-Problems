class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int l = 0, r = 0, maxLen = 0, maxFreq = 0;

        unordered_map<char, int> mpp;

        for (char c = 'A'; c <= 'Z'; ++c) {
            mpp[c] = 0;
        }

        while(r < s.size()){

            mpp[s[r]]++;

            maxFreq = max(maxFreq , mpp[s[r]]);

            while((r - l + 1) - maxFreq > k){
                mpp[s[l]]--;
                maxFreq = 0;

                for(const auto& [c, i] : mpp){
                    maxFreq = max(maxFreq, i);
                }
                l++;
            }

            maxLen = max(maxLen, r-l+1);
            r++;
        }

        return maxLen;
    }
};