class Solution {
public:
    int beautySum(string s) {
        
        int total = 0;

        for(int i = 0; i < s.size(); i++){

            unordered_map<char, int> freq;

            for(int j = i; j < s.size(); j++){

                freq[s[j]]++;

                int maxF = 0, minF = INT_MAX;

                for(auto& [ch, count] : freq){

                    maxF = max(maxF, count);
                    minF = min(minF, count);
                }

                total += (maxF - minF);
            }
        }
        
        return total;
    }
};